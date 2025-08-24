#include<iostream>

#define MAX (123456*2)

using namespace std;

int n, ans;
bool num[MAX+1];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    for(int i = 2; i*i <= MAX; i++)
    {
        if(num[i]) continue; 
        for(int j = 2; i*j <= MAX; j++) num[i*j] = true;
    }

    while(true)
    {
        cin >> n;
        if(n == 0) break;

        ans = 0;

        for(int i = n+1; i <= n*2; i++)
        {
            if(!num[i]) ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}