#include<iostream>
#include<queue>

using namespace std;

int N, M, ans;
int paper[501][501] = {0, };

bool visit[501][501];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void tetro(int y, int x, int d, int cnt)
{
    visit[y][x] = true;
    cnt += paper[y][x];
    
    if(d == 4) 
    {
        ans = max(ans, cnt);
        visit[y][x] = false;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || N <= ny || M <= nx) continue;
        if(!visit[ny][nx]) tetro(ny, nx, d+1, cnt);
    }

    visit[y][x] = false;

    // ㅏ
    if(0 <= y-1 && 0 <= x-1 && y+1 < N) 
        ans = max(ans, paper[y][x]+paper[y-1][x-1]+paper[y][x-1]+paper[y+1][x-1]);

    // ㅓ
    if(0 <= y-1 && y+1 < N && x+1 < M)
        ans = max(ans, paper[y][x]+paper[y-1][x+1]+paper[y][x+1]+paper[y+1][x+1]);

    // ㅗ
    if(0 <= y-1 && 0 <= x-1 && x+1 < M)
        ans = max(ans, paper[y][x]+paper[y-1][x-1]+paper[y-1][x]+paper[y-1][x+1]);

    // ㅜ
    if(0 <= x-1 && y+1 < N && x+1 < M)
        ans = max(ans, paper[y][x]+paper[y+1][x-1]+paper[y+1][x]+paper[y+1][x+1]);
}

int main()
{
    fastio();
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> paper[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            tetro(i, j, 1, 0);
        }
    }

    cout << ans;
    return 0;
}