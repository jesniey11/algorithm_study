#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int L, R, C;
int ez, ey, ex;
char arr[31][31][31];

queue<pair<int, pair<int, int>>> q;
int visit[31][31][31];

int dz[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 0, -1, 1};

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void init()
{
    memset(visit, 0, sizeof(visit));
    while(!q.empty()) q.pop();
}

bool input()
{
    cin >> L >> R >> C;
    if(L == 0 && R == 0 && C == 0) return false;

    init();

    for(int k = 0; k < L; k++) 
    {
        for(int i = 0; i < R; i++) 
        {
            for(int j = 0; j < C; j++)
            {
                cin >> arr[k][i][j];
                if(arr[k][i][j] == 'S') 
                {
                    q.push({k, {i, j}});
                    visit[k][i][j] = 1;
                }
                if(arr[k][i][j] == 'E') ez = k, ey = i, ex = j;
            }
        }
    }

    return true;
}

bool BFS()
{
    while(!q.empty())
    {
        pair<int, pair<int, int>> p = q.front(); q.pop();

        int zz = p.first;
        int yy = p.second.first;
        int xx = p.second.second;

        if(zz == ez && yy == ey && xx == ex) return true;

        for(int i = 0; i < 6; i++)
        {
            int nz = zz + dz[i];
            int ny = yy + dy[i];
            int nx = xx + dx[i];

            if(nx < 0 || ny < 0 || nz < 0 || C <= nx || R <= ny || L <= nz) continue;
            if(arr[nz][ny][nx] == '#' || visit[nz][ny][nx] != 0) continue;

            q.push({nz, {ny, nx}});
            visit[nz][ny][nx] = visit[zz][yy][xx] + 1;
        }
    }

    return false;
}

int main()
{
    fastio();

    while(input())
    {
        if(BFS()) cout << "Escaped in " << visit[ez][ey][ex]-1 << " minute(s).\n";
        else cout << "Trapped!\n";
    }

    return 0;
}