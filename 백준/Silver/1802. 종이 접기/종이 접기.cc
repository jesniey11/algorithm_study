#include<iostream>

using namespace std;

int T;
string str;

bool fold(int start, int end)
{
    if(end <= start) return true;

    int s = start, e = end;
    while(s < e)
    {
        if(str[s] != str[e]) s++, e--;
        else return false;
    }

    return fold(start, e-1);
}

int main()
{
    cin >> T;
    
    for(int tc = 0; tc < T; tc++)
    {
        cin >> str;
        
        if(fold(0, str.size()-1)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}