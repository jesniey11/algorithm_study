#include<iostream>
#include<queue>

using namespace std;

int n, m, arr[500][500];
int num = 0, wid = 0;

queue<pair<int, int>> q;
bool visit[500][500];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int BFS(int y, int x)
{
    int cnt = 0;
    q.push({y, x});
    visit[y][x] = true;

    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();
        cnt++;

        for(int i = 0; i < 4; i++) 
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(ny < 0 || nx < 0 || n <= ny || m <= nx) continue;
            if(visit[ny][nx] || arr[ny][nx] == 0) continue;

            visit[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    
    return cnt;
}

int main()
{
    fastin();

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) cin >> arr[i][j];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1 && !visit[i][j]) 
            {
                wid = max(wid, BFS(i, j));
                num++;
            }
        }
    }

    cout << num << "\n" << wid;
    return 0;
}