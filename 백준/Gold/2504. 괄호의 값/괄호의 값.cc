#include<iostream>
#include<stack>

using namespace std;

stack<char> stk;
int ans = 0, cnt = 1;
string s;

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int cost(char c)
{
    if(c == '(') return 2;
    else return 3;
}

char comp(char c)
{
    if(c == ')') return '(';
    else return '[';
}

int main()
{
    fastin();

    cin >> s;
    for(int i = 0; i < s.size(); i++) 
    {
        if(s[i] == '(' || s[i] == '[') 
        {
            cnt *= cost(s[i]);
            stk.push(s[i]);
        }
        else 
        {   
            if(stk.empty() || stk.top() != comp(s[i])) 
            {
                cout << 0; 
                return 0;
            }

            if(s[i-1] == comp(s[i])) ans += cnt;
            cnt /= cost(comp(s[i]));
            stk.pop();
        }
    }

    if(stk.empty()) cout << ans;
    else cout << 0;

    return 0;
}