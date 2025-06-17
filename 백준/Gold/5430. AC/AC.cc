#include<iostream>
#include<sstream>
#include<deque>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void parse(string s, deque<int> &dq) 
{
    if (s == "[]") return;
    s = s.substr(1, s.size()-2);

    stringstream ss(s);
    string tmp = "";

    while(getline(ss, tmp, ',')) dq.push_back(stoi(tmp));
}

string answer(deque<int> &dq, bool b)
{
    string ans = "[";
    
    while(!dq.empty())
    {
        if(b) 
        {
            ans += to_string(dq.front());
            dq.pop_front();
        }
        else
        {
            ans += to_string(dq.back());
            dq.pop_back();
        }
        
        if(!dq.empty()) ans += ",";
    }

    return ans + "]";
}

int main()
{
    fastio();

    int T;
    cin >> T;
    while(T--)
    {
        int n;
        deque<int> dq;
        string f, in;

        cin >> f >> n >> in;
        parse(in, dq);

        bool isError = false, isHead = true;
        for(int i = 0; i < f.size(); i++) 
        {
            if(f[i] == 'R') isHead = !isHead;
            if(f[i] == 'D') 
            {
                if(dq.empty()) 
                {
                    isError = true; break;
                }
                else
                {
                    if(isHead) dq.pop_front();
                    else dq.pop_back();
                }
            }
        }

        if(isError) cout << "error" << "\n";
        else cout << answer(dq, isHead) << "\n";
    }

    return 0;
}