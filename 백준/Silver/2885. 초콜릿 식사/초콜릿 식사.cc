#include<iostream>

using namespace std;

int main()
{
    int K;
    cin >> K;

    int N = 1;
    while(N < K) N <<= 1;

    int cnt = 0;
    for(int i = K; i != 0; i &= (i-1)) cnt++;

    int ans = 0, tmp = 0;
    for(int i = N; tmp < cnt; i >>= 1) 
    {
        if(K & i) tmp++;
        ans++;
    }

    cout << N << " " << ans-1;
    return 0;
}