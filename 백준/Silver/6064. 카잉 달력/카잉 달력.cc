#include<iostream>

using namespace std;
int gcd(int a, int b)
{
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 0; t < tc; t++)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int doom = lcm(M, N);
        bool flag = false;

        for(int i=x; i<=doom; i+=M)
        {
            int b = i%N;
            if(b == 0) b = N;

            if(b == y)
            {
                cout << i << "\n";
                flag = true;
                break;
            }
        }

        if(!flag) cout << -1 << "\n";
    }
    return 0;
}