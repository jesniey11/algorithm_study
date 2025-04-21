#include<iostream>
#define INF 999999999

using namespace std;

int main()
{
    int N, S, ans = INF;
    cin >> N >> S;

    int arr[100001];
    for(int i = 0; i < N; i++) cin >> arr[i];

    int l = 0, r = 0, sum = 0;
    while(l <= r && r <= N) 
    {
        if(sum < S) 
        {
            sum += arr[r];
            r++;
        }
        else 
        {
            ans = min(ans, r-l);

            sum -= arr[l];
            l++;
        }
    }

    if(ans == INF) ans = 0;
    cout << ans;
    return 0;
}