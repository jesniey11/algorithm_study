#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int N, arr[1001], dp[1001];

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < i; j++) 
        {
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    sort(dp, dp + N);

    cout << dp[N-1];
    return 0;
} 