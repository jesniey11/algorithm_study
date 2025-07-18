#include<iostream>
#include<cstring>
#include<queue>
#include<tuple>

using namespace std;

int N, M;
char board[11][11];

pair<int, int> red, blue;

int dist[11][11][11][11];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int BFS()
{
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(red.first, red.second, blue.first, blue.second));
    dist[red.first][red.second][blue.first][blue.second] = 0;

    while(!q.empty())
    {
        int rx, ry, bx, by;
        tie(rx, ry, bx, by) = q.front(); q.pop();

        int cnt = dist[rx][ry][bx][by];
        if(cnt >= 10) return -1;

        for(int d = 0; d < 4; d++)
        {     
            int nrx = rx, nry = ry;
            int nbx = bx, nby = by;
            
            while(board[nbx+dx[d]][nby+dy[d]] == '.')
            {
                nbx += dx[d], nby += dy[d];
            }
            if(board[nbx+dx[d]][nby+dy[d]] == 'O') continue;

            while(board[nrx+dx[d]][nry+dy[d]] == '.')
            {
                nrx += dx[d], nry += dy[d];
            }
            if(board[nrx+dx[d]][nry+dy[d]] == 'O') return cnt + 1;

            // 구슬 겹침 처리
            if(nrx == nbx && nry == nby) 
            {
                // 방향 경계값(0 or N)에 가깝게 있던 구슬 
                // => 더 빨리 온 구슬

                switch (d)
                {
                    case 0: if(rx < bx) nbx++; else nrx++; break;
                    case 1: if(rx < bx) nrx--; else nbx--; break;
                    case 2: if(ry < by) nby++; else nry++; break;
                    case 3: if(ry < by) nry--; else nby--; break;
                }
            }

            if(dist[nrx][nry][nbx][nby] != -1) continue;
            
            dist[nrx][nry][nbx][nby] = cnt + 1;
            q.push({nrx, nry, nbx, nby});
        }
    }

    return -1;
}

int main()
{
    fastin();
    memset(dist, -1, sizeof(dist));

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++) 
        {
            cin >> board[i][j];

            if(board[i][j] == 'R') 
            {
                red = {i, j};
                board[i][j] = '.';
            }

            if(board[i][j] == 'B') 
            {
                blue = {i, j};
                board[i][j] = '.';
            }
        }
    }

    cout << BFS();

    return 0;
}