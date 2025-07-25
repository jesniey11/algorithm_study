#include<iostream>
#include<stack>

using namespace std;

int ans = 0;
string s;
stack<char> stk;

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') stk.push(s[i]);
        else 
        {
            stk.pop();
            if(s[i-1] == '(') ans += stk.size();
            else ans++;
        }
    }

    cout << ans;
    return 0;
}