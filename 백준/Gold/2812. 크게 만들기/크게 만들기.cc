#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    int N, K, cnt = 0;
    string S;
    cin >> N >> K >> S;

    stack<char> stk, ans;
    for(int i = 0; i < N; i++) 
    {
        while(!stk.empty() && cnt < K && stk.top() < S[i]) 
        {
            stk.pop();
            cnt++;
        }
        stk.push(S[i]);
    }

    while(cnt < K) 
    {
        stk.pop();
        cnt++;
    }
    
    while(!stk.empty()) 
    {
        ans.push(stk.top());
        stk.pop();
    }

    while(!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }

    return 0;
}