#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int tc, n, last;
    int dp[10001][4];
    int ans[10001];
    
    dp[0][1] = 1;
    dp[0][2] = 0;
    dp[0][3] = 0;

    last = 1;

    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        cin >> n;
        
        for(int i = last; i <= n; i++)
        {
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-2][1]+dp[i-2][2];
            dp[i][3] = dp[i-3][1]+dp[i-3][2]+dp[i-3][3];

            ans[i] = dp[i][1]+dp[i][2]+dp[i][3];
        }
        
        last = n;

        cout << ans[n] << "\n";
    }
    
    return 0;
}