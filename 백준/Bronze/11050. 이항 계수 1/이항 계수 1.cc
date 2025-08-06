#include<iostream>

using namespace std;

int N, K, ans;

int facto(int x)
{
    int ret = 1;
    for(int i = x; i > 0; i--) ret *= i;
    return ret;
}

int main()
{
    cin >> N >> K;
    ans = facto(N) / (facto(K) * facto(N-K));
    cout << ans;
    
    return 0;
}