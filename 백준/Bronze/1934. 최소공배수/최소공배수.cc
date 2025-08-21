#include<iostream>

using namespace std;

int tc, A, B, ans;

int gcd(int a, int b)
{
    int r = a % b;

    if(r == 0) return b;
    else return gcd(b, r);
}

int main()
{
    cin >> tc;
    while(tc--)
    {
        cin >> A >> B;
        ans = (A*B) / gcd(A, B);
        
        cout << ans << '\n';
    }

    return 0;
}