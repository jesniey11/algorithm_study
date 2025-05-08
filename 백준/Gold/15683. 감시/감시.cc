#include<iostream>
#include<vector>

using namespace std;

int N, M, ans = 999999999;
int office[9][9];

vector<pair<int,int>> cctv;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++) 
        {
            cin >> office[i][j];
            if(office[i][j] != 0 && office[i][j] != 6) cctv.push_back({i, j});
        }
    }
}

void check(int x, int y, int d)
{
    d %= 4;

    while(true) 
    {
        x += dx[d];
        y += dy[d];

        if(x < 0 || y < 0 || N <= x || M <= y || office[x][y] == 6) return;
        if(office[x][y] == 0) office[x][y] = 9;
    }

}

void DFS(int depth)
{
    if(depth == cctv.size())
    {
        int cnt = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++) 
            {
                if(office[i][j] == 0) cnt++;
            }
        }

        ans = min(ans, cnt);
        return;
    }

    int x = cctv[depth].first;
    int y = cctv[depth].second;
    
    int copy[9][9];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++) copy[i][j] = office[i][j];
    }

    for(int d = 0; d < 4; d++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++) copy[i][j] = office[i][j];
        }

        switch (office[x][y])
        {
            case 1:
                check(x, y, d);
                break;
            
            case 2:
                check(x, y, d);
                check(x, y, d+2);
                break;
        
            case 3:
                check(x, y, d);
                check(x, y, d+1);
                break;

            case 4:
                check(x, y, d);
                check(x, y, d+1);
                check(x, y, d+2);
                break;
            
            case 5:
                for(int i = 0; i < 4; i++) check(x, y, d+i);
                break;
        }
        
        DFS(depth+1);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++) office[i][j] = copy[i][j];
        }
    }
}

int main()
{
    fastio();
    input();
    
    DFS(0);
    cout << ans;
    
    return 0;
}