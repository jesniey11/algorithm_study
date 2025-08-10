#include<iostream>

using namespace std;

int n;
int arr[10001], dp[10001];

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    dp[0] = 0; 
    dp[1] = arr[1]; 
    dp[2] = arr[1] + arr[2];

    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(max(dp[i-1], dp[i-2]+arr[i]), dp[i-3] + arr[i-1] + arr[i]); 
    }

    cout << dp[n];
    return 0;
}