#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int N, num = 0, ans = 999999;
int arr[101][101], mvist[101][101], bvist[101][101];
queue<pair<int, int>> q;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void mark(int y, int x)
{
    q.push({y, x});
    mvist[y][x] = 1;

    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();
        arr[p.first][p.second] = num;

        for(int i = 0; i < 4; i++)
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(ny < 0 || nx < 0 || N <= ny || N <= nx) continue;
            if(mvist[ny][nx] == 1 || arr[ny][nx] == 0) continue;

            q.push({ny, nx});
            mvist[ny][nx] = 1;
        }
    }
}

void bridge()
{
    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(ny < 0 || nx < 0 || N <= ny || N <= nx) continue;

            // 같은섬
            if(arr[ny][nx] == arr[p.first][p.second]) continue;

            // 다른섬
            if(arr[ny][nx] != 0) ans = min(ans, bvist[ny][nx] + bvist[p.first][p.second]);
            
            // 바다
            else 
            {
                q.push({ny, nx});
                arr[ny][nx] = arr[p.first][p.second];
                bvist[ny][nx] = bvist[p.first][p.second] + 1;
            }
        }
    }
}

int main()
{
    fastin();

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) cin >> arr[i][j];
    }

    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) 
        {
            if(arr[i][j] == 0 || mvist[i][j]) continue;
            
            num++;
            mark(i, j);
        }
    }

    memset(bvist, -1, sizeof(bvist));

    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) 
        {
            if(arr[i][j] == 0) continue;

            q.push({i, j});
            bvist[i][j] = 0;
        }
    }
    bridge();

    cout << ans;
    return 0;
}