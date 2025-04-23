#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
    string str, exp, ans = "";
    stack<char> s;
    cin >> str >> exp;
    
    for(int i = 0; i < str.size(); i++) 
    {
        s.push(str[i]);

        if(str[i] == exp[exp.size()-1] && exp.size() <= s.size())
        {
            string tmp = "";
            for(auto a:exp)
            {
                tmp.push_back(s.top());
                s.pop();
            }

            reverse(tmp.begin(), tmp.end());

            if(tmp.compare(exp)) 
            {
                for(int j = 0; j < tmp.size(); j++) s.push(tmp[j]);
            }
        }
    }

    while(!s.empty()) 
    {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());

    if(ans.size() == 0) ans = "FRULA";
    cout << ans;
    return 0;
}