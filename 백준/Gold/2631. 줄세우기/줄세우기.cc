#include<iostream>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int N, ans = 0, kids[201], dp[201];
    
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> kids[i];
    
    for(int i = 1; i <= N; i++) 
    {
        dp[i] = 1;
        for(int j = 1; j <= i; j++) 
        {
            if(kids[i] > kids[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    cout << N - ans;
    return 0;
}