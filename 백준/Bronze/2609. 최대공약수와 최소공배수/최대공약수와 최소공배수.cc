#include<iostream>

using namespace std;

int func(int a, int b)
{
    int c = a%b;
    while (c != 0) 
    {
        a = b;
        b = c;
        c = a%b;
    }

    return b;
}

int main()
{
    int a, b, out1, out2;
    cin >> a >> b;

    out1 = func(a, b);
    out2 = a*b / out1;

    cout << out1 << "\n" << out2;
    return 0;    
}