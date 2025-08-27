#include<iostream>

using namespace std;

int N, ans = 0;
int arr[1001], dp[1001];

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i; j++) 
        {
            if(arr[i] > arr[j]) dp[i] = max(dp[i], arr[i]+dp[j]);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}