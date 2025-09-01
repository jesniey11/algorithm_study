#include<iostream>

#define MAX 1000001
#define mod 1000000009

using namespace std;

int T, n;
long long dp[MAX];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    cin >> T;
    
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for(int i = 4; i < MAX; i++) dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % mod;

    while(T--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}