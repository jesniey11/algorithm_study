#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    int m, f;
    while(true)
    {
        cin >> m >> f;
        if(m == 0 && f == 0) break;

        cout << m+f << "\n";
    }
    
    return 0;
} 
