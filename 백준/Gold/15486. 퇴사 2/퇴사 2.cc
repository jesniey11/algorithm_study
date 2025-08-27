#include<iostream>

#define MAX 1500001

using namespace std;

int N, nxt, ans = 0;
int t[MAX], p[MAX], dp[MAX];

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> t[i] >> p[i];

    for(int i = N; i >= 1; i--) 
    {
        nxt = i+t[i];

        if(nxt <= N+1) dp[i] = max(dp[i+1], dp[nxt]+p[i]);
        else dp[i] = dp[i+1];

        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}