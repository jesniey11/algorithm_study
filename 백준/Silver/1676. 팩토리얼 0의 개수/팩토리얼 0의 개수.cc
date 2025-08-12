#include<iostream>

using namespace std;

int N, ans = 0;

int main()
{
    cin >> N;

    for(int i = 5; i <= N; i *= 5) ans += N/i;

    cout << ans;
    return 0;
}