#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[1000001];

void fastio()
{
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int main()
{
    fastio();

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr+N, greater<>());

    for(int i = 0; i < N; i++) cout << arr[i] << "\n"; 
    return 0;
} 