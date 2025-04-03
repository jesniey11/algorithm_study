#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int num[50001] = {0, };

    for(int i = 1; i <= n; i++)
    {
        num[i] = num[i-1] + 1;
        for(int j = 1; j*j <= i; j++)
        {
            num[i] = min(num[i], num[i-(j*j)]+1);
        }
    }
    cout << num[n];
    
    return 0;
}