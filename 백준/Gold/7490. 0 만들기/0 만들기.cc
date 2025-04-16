#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int N;
vector<string> ans;

void solve(int n, int sum, string s)
{
    if(n == N+1)
    {
        if(sum == 0) ans.push_back(s.erase(0, 1));
        return;
    }
    
    // +
    solve(n+1, sum+n, s + '+' + to_string(n));

    // -
    if(n != 1) solve(n+1, sum-n, s + '-' + to_string(n));

    // 공백
    if(N-1 < n) return;
    solve(n+2, sum + (10*n + n+1), s + '+' + to_string(n) + ' ' + to_string(n+1));
    if(n != 1) solve(n+2, sum - (10*n + n+1), s + '-' + to_string(n) + ' ' + to_string(n+1));
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        cin >> N;
        solve(1, 0, "");
        sort(ans.begin(), ans.end());  
        
        for(auto v:ans) cout << v << "\n";
        
        cout << "\n";

        ans.clear();
    }

    return 0;
}