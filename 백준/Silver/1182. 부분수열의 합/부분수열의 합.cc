#include<iostream>

using namespace std;

int N, S, ans;
int arr[21];

void backtrack(int i, int sum)
{
    if(i == N)
    {
        if(sum == S) ans++;
        return;
    }

    backtrack(i+1, sum);
    backtrack(i+1, sum+arr[i]);
}

int main()
{
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> arr[i];

    backtrack(0, 0);
    if(S == 0) ans--;

    cout << ans;
    return 0;
}