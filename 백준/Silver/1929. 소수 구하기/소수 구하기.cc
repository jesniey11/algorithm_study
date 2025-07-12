#include<iostream>
#include<math.h>

using namespace std;

int M, N;
int arr[1000001];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    cin >> M >> N;
    for(int i = 2; i <= N; i++) arr[i] = i;

    for(int i = 2; i <= sqrt(N); i++) 
    {
        if(arr[i] == 0) continue;
        for(int j = 2*i; j <= N; j+=i) arr[j] = 0;
    }

    for(int i = M; i <= N; i++) 
    {
        if(arr[i] != 0) cout << i << "\n";
    }

    return 0;
}