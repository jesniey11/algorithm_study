#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int N, H = 0, ans = 0; 
int arr[101][101];

queue<pair<int, int>> q;
bool visit[101][101];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void BFS(int y, int x, int h)
{
    q.push({y, x});
    visit[y][x] = true;

    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(ny < 0 || nx < 0 || N <= ny || N <= nx) continue;
            if(visit[ny][nx] || arr[ny][nx] <= h) continue;

            q.push({ny, nx});
            visit[ny][nx] = true;
        }
    }
}

int main()
{
    fastin();

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) 
        {
            cin >> arr[i][j];
            H = max(H, arr[i][j]);
        }
    }

    for(int h = 0; h < H; h++) 
    {
        int cnt = 0;
        memset(visit, false, sizeof(visit));

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(arr[i][j] > h && !visit[i][j]) 
                {
                    BFS(i, j, h);
                    cnt++;
                }
            } 
        }

        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}