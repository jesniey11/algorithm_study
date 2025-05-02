#include<iostream>
#include<queue>

using namespace std;

int N, M, ans;
string map[1001];
bool visit[1001][1001][2];
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int BFS()
{
    queue<pair<pair<int, int>, pair<int, bool>>> q;

    q.push({{0, 0}, {1, false}});
    visit[0][0][0] = true;

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        bool wall = q.front().second.second;
        q.pop();

        if(x == N-1 && y == M-1) return cnt;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nw = wall;

            if(nx < 0 || N <= nx || ny < 0 || M <= ny || visit[nx][ny][nw]) continue;
            if(map[nx][ny] == '1') 
            {
                if(wall) continue;
                nw = true;
            }

            visit[nx][ny][nw] = true;
            q.push({{nx, ny}, {cnt+1, nw}});
        }
    }

    return -1;    
}

int main()
{
    fastio();
    cin >> N >> M;
    for(int n = 0; n < N; n++) cin >> map[n];

    cout << BFS();

    return 0;
}