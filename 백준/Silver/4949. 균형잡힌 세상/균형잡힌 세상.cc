#include<iostream>
#include<string>
#include<stack>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    while(true)
    {
        string s = "";
        bool b = true;
        stack<char> stk;
        
        getline(cin, s);

        if(s == ".") break;

        for(int i = 0; i < s.size(); i++) 
        {
            if(s[i] == '(' || s[i] == '[') stk.push(s[i]);

            if(s[i] == ')')
            {
                if(stk.empty() || stk.top() != '(') 
                {
                    b = false; 
                    break;
                }
                else stk.pop();
            }

            if(s[i] == ']')
            {
                if(stk.empty() || stk.top() != '[') 
                {
                    b = false; 
                    break;
                }
                else stk.pop();
            }
        }
        if(!stk.empty()) b = false;

        if(b) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

    return 0;
}