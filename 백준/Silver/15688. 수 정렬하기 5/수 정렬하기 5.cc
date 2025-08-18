#include<iostream>

#define MAX 1000001

using namespace std;

int N, x;
int num[2*MAX];

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
        cin >> x;
        num[x+1000000]++;
    }

    for(int i = 0; i <= 2000000; i++) 
    {
        while(num[i]--) cout << i-1000000 << '\n';
    }

    return 0;
}