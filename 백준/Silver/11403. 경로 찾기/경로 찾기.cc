#include<iostream>

using namespace std;

int N;
int G[101][101] = {0, };

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> G[i][j];
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            for(int k = 1; k <= N; k++)
            {
                if(G[i][k] == 1 && G[j][i]== 1) G[j][k] = 1;
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << G[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}