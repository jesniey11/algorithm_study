#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int arr[9], visit[9], ans[9];

void solve(int n)
{
    if(n == M) 
    {
        for(int i = 0; i < M; i++) cout << ans[i] << " ";
        cout << "\n";

        return;
    }

    int tmp = 0;
    for(int i = 0; i < N; i++) 
    {
        if(visit[i] || tmp == arr[i]) continue;
        
        visit[i] = 1;
        tmp = ans[n] = arr[i];
        solve(n+1);
        visit[i] = 0;
    }
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr+N);
    solve(0);

    return 0;
}