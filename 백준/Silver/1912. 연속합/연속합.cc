#include<iostream>

using namespace std;

int n, ans = -999999999;
int arr[100001], dp[100001];

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++)
    {
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}