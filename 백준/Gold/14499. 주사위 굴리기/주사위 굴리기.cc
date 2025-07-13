#include<iostream>

using namespace std;

int N, M, X, Y, K;
int arr[22][22];
int cmd;
int dice[6];
int dir[5][6] = // dir[1] 윗면, dir[3] 바닥
{
    {}, // 0
    {0, 4, 2, 5, 3, 1}, // 동
    {0, 5, 2, 4, 1, 3}, // 서
    {3, 0, 1, 2, 4, 5}, // 북
    {1, 2, 3, 0, 4, 5}  // 남
};

// 0, 동, 서, 남, 북
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void roll(int c)
{
    int tmp[6];

    for(int i = 0; i < 6; i++) tmp[i] = dice[i];
    for(int i = 0; i < 6; i++) dice[i] = tmp[dir[c][i]];
}

void solve(int c)
{
    int nx = X + dx[c];
    int ny = Y + dy[c];
    if(nx < 0 || ny < 0 || N <= nx || M <= ny) return;

    roll(c);

    if(arr[nx][ny] == 0) arr[nx][ny] = dice[3];
    else 
    {
        dice[3] = arr[nx][ny];
        arr[nx][ny] = 0;
    }

    X = nx, Y = ny;
    cout << dice[1] << "\n";
}

int main()
{
    fastio();

    cin >> N >> M >> X >> Y >> K;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++) cin >> arr[i][j];
    }

    while(K--)
    {
        cin >> cmd;
        solve(cmd);
    }

    return 0;
}