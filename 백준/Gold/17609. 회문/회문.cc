#include<iostream>

using namespace std;

string str;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int palindrome(int s, int e, int del)
{
    while(s < e)
    {
        if(str[s] == str[e])
        {
            s++; e--;
            continue;
        }

        if(del == 0) 
        {
            if(palindrome(s+1, e, 1) == 0 || palindrome(s, e-1, 1) == 0) return 1;
            return 2;
        }
        else return 2;

    }

    return 0;
}


int main()
{
    fastio();

    int T;
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        cin >> str;
        cout << palindrome(0, str.size()-1, 0) << "\n";
    }
    
    return 0;
}