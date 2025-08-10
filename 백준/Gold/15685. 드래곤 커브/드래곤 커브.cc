#include<iostream>
#include<vector>

using namespace std;

int N, x, y, d, g, ans = 0;
bool arr[101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void fastin()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y >> d >> g;   
        arr[x][y] = true;

        vector<int> dir;
        dir.push_back(d);

        for(int gen = 0; gen < g; gen++)
        {
            int size = dir.size() - 1;
            for(int j = size; j >= 0; j--)
            {
                int nd = (dir[j] + 1) % 4;
                dir.push_back(nd);
            }
        }

        int nx = x;
        int ny = y;

        for(auto a : dir)
        {
            nx += dx[a];
            ny += dy[a];
            
            arr[nx][ny] = true;
        }
    }

    for(int i = 0; i < 100; i++) 
    {
        for(int j = 0; j < 100; j++) 
        {
            if(arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]) ans++;
        } 
    }

    cout << ans;
    return 0;
}