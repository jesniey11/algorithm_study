#include<iostream>

using namespace std;

string str;

int main()
{
    while(true)
    {
        cin >> str;
        if(str == "0") break;

        int n = str.size()-1;
        bool flag = true;

        for(int i = 0; i < str.size()/2; i++)
        {
            if(str[i] != str[n-i]) 
            {
                flag = false;
                break;
            }
        }

        if(flag) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}