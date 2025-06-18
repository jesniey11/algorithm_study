#include<iostream>
#include<stack>

using namespace std;

int N, ans = 0;
string s = "";

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        stack<char> stk;

        cin >> s;
        for(int j = 0; j < s.size(); j++) 
        {
            if(!stk.empty() && stk.top() == s[j]) stk.pop();
            else stk.push(s[j]);
        }

        if(stk.empty()) ans++;
    }

    cout << ans;
    return 0;
}