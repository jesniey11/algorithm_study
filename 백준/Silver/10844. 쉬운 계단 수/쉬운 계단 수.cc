#include<iostream>

using namespace std;

int N;
long long ans = 0;
int mod = 1000000000;
int dp[101][10];

int main()
{
    cin >> N;

    for(int i = 1; i <= 9; i++) dp[1][i] = 1;

    for(int i = 2; i <= N; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            if(j == 0) dp[i][j] = dp[i-1][j+1] % mod;
            else if(j == 9) dp[i][j] = dp[i-1][j-1] % mod;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
        }
    }

    for(int i = 0; i <= 9; i++) ans += dp[N][i];
    cout << ans % mod; 

    return 0;
}