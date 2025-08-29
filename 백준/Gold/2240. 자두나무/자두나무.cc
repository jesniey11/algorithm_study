#include<iostream>

using namespace std;

int T, W, ans;
int tree[1001], dp[1001][31][3];

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();
    
    cin >> T >> W;
    for(int i = 1; i <= T; i++) cin >> tree[i];

    int cnt = 0;
    for(int i = 1; i <= T; i++) 
    {
        if(tree[i] == 1) cnt++;
        dp[i][0][1] = cnt;
    }

    for(int i = 1; i <= T; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            if(tree[i] == 1)
            {
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2]) + 1;
                dp[i][j][2] = max(dp[i-1][j-1][1], dp[i-1][j][2]);
            }
            else 
            {
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2]);
                dp[i][j][2] = max(dp[i-1][j-1][1], dp[i-1][j][2]) + 1;
            }
        }
    }

    for (int i = 0; i <= W; i++)
    {
        ans = max(ans, max(dp[T][i][1], dp[T][i][2]));
    }
    
    cout << ans;
    return 0;
}