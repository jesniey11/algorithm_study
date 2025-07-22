#include<iostream>

using namespace std;

int N, n, arr[10001];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        cin >> n;
        arr[n]++;
    }

    for(int i = 1; i < 10001; i++)
    {
        while(arr[i] > 0) 
        {
            cout << i << "\n"; 
            arr[i]--;
        }
    }

    return 0;
}