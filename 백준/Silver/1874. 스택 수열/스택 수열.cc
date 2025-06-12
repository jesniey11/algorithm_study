#include<iostream>
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
    
    int n, cnt = 1; 
    stack<int> stk;
    string ans = "";
    
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;

        while(cnt <= x) 
        {
            stk.push(cnt);
            cnt += 1;
            ans += "+\n";
        }

        if(stk.top() != x) 
        {
            cout << "NO"; return 0;
        }
        
        stk.pop();
        ans += "-\n";
    }

    cout << ans;
    return 0;
}