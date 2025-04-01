#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int square[1001];
    square[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        if(i%2 == 0) square[i] = (2*square[i-1] + 1) % 10007;
        else square[i] = (2*square[i-1] - 1) % 10007;
    }

    cout << square[n];
    return 0;
}