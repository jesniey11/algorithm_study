#include<iostream>
#include<queue>

using namespace std;

int N, M, ans = 0;
char board[601][601];

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void BFS(int x, int y) 
{
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    queue<pair<int, int>> q;
    bool visit[601][601] = {false, };

    q.push({x, y});
    visit[x][y] = true;

    while(!q.empty()) 
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        if(board[nx][ny] == 'P') ans++;

        for(int i = 0; i < 4; i++) 
        {
            int tx = nx+dx[i];
            int ty = ny+dy[i];

            if(tx < 0 || ty < 0 || N <= tx || M <= ty) continue;
            if(visit[tx][ty] || board[tx][ty] == 'X') continue;
            
            visit[tx][ty] = true;
            q.push({tx, ty});
        }
    }

    return;
}

int main()
{
    fastio();
    cin >> N >> M;

    int x, y;
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < M; j++) 
        {
            cin >> board[i][j];
            if(board[i][j] == 'I') {x = i; y = j;}
        }
    }

    BFS(x, y);

    if(ans == 0) {cout << "TT";}
    else cout << ans;

    return 0;
}