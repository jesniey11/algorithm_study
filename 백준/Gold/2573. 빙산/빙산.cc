#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int N, M, cnt, ans = 0;
int now[301][301], nex[301][301];

queue<pair<int, int>> q;
bool visit[301][301];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void init()
{
    cnt = 0;
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < M; j++) 
        {
            nex[i][j] = now[i][j];
            visit[i][j] = 0;
        }
    }
}

void BFS(int y, int x)
{
    q.push({y, x});
    visit[y][x] = true;

    while(!q.empty())
    {
        int sea = 0;
        pair<int, int> p = q.front(); q.pop();

        for(int i = 0; i < 4; i++) 
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(ny < 0 || nx < 0 || N <= ny || M <= nx) continue;
            if(visit[ny][nx]) continue;
            
            if(now[ny][nx] == 0) sea++;
            else 
            {
                q.push({ny, nx});
                visit[ny][nx] = true;
            }
        }

        nex[p.first][p.second] = max(0, nex[p.first][p.second]-sea);
    }
}

int main()
{
    fastin();

    cin >> N >> M;
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < M; j++) cin >> now[i][j];
    }

    while(true)
    {
        init();
        for(int i = 0; i < N; i++) 
        {
            for(int j = 0; j < M; j++) 
            {
                if(!visit[i][j] && now[i][j] != 0)
                {
                    BFS(i, j);
                    cnt++;
                }
            }
        }

        if(cnt == 0) 
        {
            ans = 0; break;
        }

        if(cnt >= 2) break;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++) now[i][j] = nex[i][j];
        }
        ans++;
    }

    cout << ans;
    return 0;
}
