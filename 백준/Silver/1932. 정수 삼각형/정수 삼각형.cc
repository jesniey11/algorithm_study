#include<iostream>

using namespace std;

int n, ans = 0;
int dp[501][501];

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++) cin >> dp[i][j];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++) 
        {
            if(j == 0) dp[i][j] += dp[i-1][0];
            else if(j == i) dp[i][j] += dp[i-1][j-1];
            else dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
            
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}