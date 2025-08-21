#include<iostream>

using namespace std;

int tc, A, B, ans;

int main()
{
    cin >> tc;
    while(tc--)
    {
        cin >> A >> B;

        ans = A;
        while(ans%B != 0) ans += A;

        cout << ans << '\n';
    }

    return 0;
}