#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int arr[9], ans[9];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve(int n, int next)
{
    if(n == M) 
    {
        for(int i = 0; i < M; i++) cout << ans[i] << " ";
        cout << "\n";

        return;
    }

    int tmp = 0;
    for(int i = next; i < N; i++) 
    {
        if(tmp == arr[i]) continue;
        
        tmp = ans[n] = arr[i];
        solve(n+1, i);
    }
}

int main()
{
    fastio();

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr+N);
    solve(0, 0);

    return 0;
}