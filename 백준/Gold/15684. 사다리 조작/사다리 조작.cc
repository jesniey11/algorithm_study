#include<iostream>
#include<vector>

#define MAX 999999999

using namespace std;

int N, M, H, a, b, ans = MAX;
bool mark[31][31];
vector<pair<int, int>> ladder;

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

bool check()
{
    for(int j = 1; j <= N; j++)
    {
        int now = j;
        for(int i = 1; i <= H; i++)
        {
            if(mark[i][now]) now++;
            else if(mark[i][now-1]) now--;
        }

        if(now != j) return false;
    }

    return true;
}

void backtrack(int idx, int cnt)
{
    if(cnt > 3) return;
    if(check()) 
    {
        ans = min(ans, cnt);
        return;
    }

    for(int i = idx; i < ladder.size(); i++)
    {
        int x = ladder[i].first;
        int y = ladder[i].second;

        if(mark[x][y] || mark[x][y-1] || mark[x][y+1]) continue;

        mark[x][y] = true;
        backtrack(i+1, cnt+1);
        mark[x][y] = false;
    }
}

int main()
{
    fastin();

    cin >> N >> M >> H;
    for(int i = 1; i <= M; i++)
    {
        cin >> a >> b;
        mark[a][b] = true;
    }

    for(int i = 1; i <= H; i++) 
    {
        for(int j = 1; j < N; j++)
        {
            if(mark[i][j] || mark[i][j-1] || mark[i][j+1]) continue;
            ladder.push_back({i, j});
        }
    }


    if(check()) cout << 0;
    else 
    {
        backtrack(0, 0);
        if(ans == MAX) cout << -1;
        else cout << ans;
    }

    return 0;
}