#include<iostream>
#include<string>

using namespace std;

int main()
{
    int N;
    long long ans = 1;
    cin >> N;

    for(int i = 2; i <= N; i++)
    {
        ans *= i;
        ans %= 10000000;

        while (ans % 10 == 0) 
        {
            ans /= 10;
        }
    }
    
    cout << ans % 10;
    return 0;
}