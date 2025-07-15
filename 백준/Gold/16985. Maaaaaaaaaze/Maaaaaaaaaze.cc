#include<iostream>
#include<algorithm>
#include<tuple>
#include<queue>
#include<cstring>

#define MAX 999999999

using namespace std;

int ans = MAX;
int cube[4][5][5][5];
int maze[5][5][5];

int order[] = {0, 1, 2, 3, 4};

queue<tuple<int, int, int>> q;
int dist[5][5][5];

int dz[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void rotate()
{
    for(int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 5; j++) // 시계 90도
        {
            for(int k = 0; k < 5; k++) cube[1][i][j][k] = cube[0][i][k][4-j];
        }

        for(int j = 0; j < 5; j++) // 시계 180도
        {
            for(int k = 0; k < 5; k++) cube[2][i][j][k] = cube[0][i][4-j][4-k];
        }

        for(int j = 0; j < 5; j++) // 시계 270도
        {
            for(int k = 0; k < 5; k++) cube[3][i][j][k] = cube[0][i][4-k][j];
        }
    }
}

int BFS()
{
    q = queue<tuple<int, int, int>>();
    memset(dist, 0, sizeof(dist));

    q.push(make_tuple(0, 0, 0));
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        tuple<int, int, int> t = q.front(); q.pop();
        
        int z, x, y;
        tie(z, x, y) = t;

        for(int d = 0; d < 6; d++)
        {
            int nz = z + dz[d];
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nz < 0 || nx < 0 || ny < 0 || 5 <= nz || 5 <= nx || 5 <= ny) continue;
            if(dist[nz][nx][ny] != 0 || maze[nz][nx][ny] == 0) continue;
            if(nz == 4 && nx == 4 && ny == 4) return dist[z][x][y];

            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push(make_tuple(nz, nx, ny));
        }
    }

    return MAX;
}

void solve()
{
    // 회전+순서 정하기 끝난 판에서 탐색
    for(int noc = 0; noc < 1024; noc++)
    {
        int c = noc;
        for(int i = 0; i < 5; i++)
        {
            int d = c % 4; 
            c /= 4;
            
            for(int j = 0; j < 5; j++) // 시계 90도
            {
                for(int k = 0; k < 5; k++) maze[i][j][k] = cube[d][order[i]][j][k];
            }
        }

        if(maze[0][0][0] == 1 && maze[4][4][4] == 1) ans = min(ans, BFS());
    }
}

int main()
{
    fastin();

    for(int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++) cin >> cube[0][i][j][k];
        }
    }

    rotate();

    do solve();
    while(next_permutation(order, order+5));

    if(ans == MAX) cout << -1;
    else cout << ans;

    return 0;
}