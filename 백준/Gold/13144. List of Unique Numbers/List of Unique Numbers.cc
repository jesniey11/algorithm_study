#include<iostream>

using namespace std;

int main()
{
    int N, arr[100001], visit[100001] = {0};
    long long ans = 0;
    cin >> N;

    for(int i = 0; i < N; i++) cin >> arr[i];

    int r = 0;
    for(int l = 0; l < N; l++) 
    {
        while(r < N) 
        {
            if(visit[arr[r]] > 0) break;

            visit[arr[r]] = 1;
            r++;
        }

        ans += r-l;
        visit[arr[l]] = 0;
    }

    cout << ans;
    return 0;
}