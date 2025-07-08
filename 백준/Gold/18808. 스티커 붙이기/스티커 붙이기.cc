#include<iostream>

using namespace std;

int N, M, K, ans = 0;
int r, c;
int laptop[41][41], sticker[11][11];

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

bool deco(int x, int y)
{
    for(int i = 0; i < r; i++) 
    {
        for(int j = 0; j < c; j++)
        {
            if(sticker[i][j] == 1 && laptop[i+x][j+y] == 1) return false;
        }
    }

    for(int i = 0; i < r; i++) 
    {
        for(int j = 0; j < c; j++)
        {
            if(sticker[i][j] == 1) laptop[i+x][j+y] = 1;
        }
    }

    return true;
}

void rotate()
{
    int tmp[11][11];
    int t;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++) tmp[i][j] = sticker[i][j];
    }
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < r; j++) sticker[i][j] = tmp[r-1-j][i];
    }

    t = r; r = c; c = t;
    return;
}

bool solve()
{
    for(int i = 0; i <= N-r; i++)
    {
        for(int j = 0; j <= M-c; j++) 
        {
            if(deco(i, j)) return true;
        }
    }

    return false;
}

int main()
{
    fastin();

    cin >> N >> M >> K;
    for(int k = 0; k < K; k++) 
    {
        cin >> r >> c;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++) cin >> sticker[i][j];
        }
        
        for(int t = 0; t < 4; t++)
        {
            if(solve()) break;
            rotate();
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++) ans += laptop[i][j];
    }

    cout << ans;
    return 0;
}