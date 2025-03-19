#include<iostream>

using namespace std;

int main()
{
    int N, ans;
    cin >> N;

    ans = 0;
    for(int i = 0; i < N; i++)
    {
        int n;
        bool flag = true;
        cin >> n;

        if(n == 1) continue;

        for(int j = 2; j < n; j++)
        {
            if(n%j == 0) flag = false;
        }

        if(flag) ans++;
    }

    cout << ans;
    return 0;
}