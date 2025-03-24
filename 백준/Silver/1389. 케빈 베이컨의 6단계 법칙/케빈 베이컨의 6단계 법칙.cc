#include<iostream>
#include<queue>
#define MAX 999999999

using namespace std;

int N, M, ans;
int tomo[101][101];
int sum[101];

int main()
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            tomo[i][j] = MAX;
        }
    }

    for(int i = 0 ; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        tomo[a][b] = 1;
        tomo[b][a] = 1;
    }

    for(int a = 1; a <= N; a++)
    {
        for(int b = 1; b <= N; b++)
        {
            for(int c = 1; c <= N; c++)
            {
                tomo[b][c] = min(tomo[b][c], tomo[b][a]+tomo[a][c]);
            }
        }
    }

    for(int a = 1; a <= N; a++)
    {
        for(int b = 1; b <= N; b++)
        {
            sum[a] += tomo[a][b];
        }

        sum[a] -= tomo[a][a];
    }
    
    ans = 1;
    for(int i = 2; i <= N; i++)
    {
        if(sum[i] < sum[ans]) 
        {
            ans = i;
        }
    }

    cout << ans;
    return 0;
}