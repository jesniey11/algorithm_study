#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, x;
vector<int> v;
vector<pair<int,int>> dp;

int main() 
{
    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        cin >> x;
        v.push_back(x);
        dp.push_back({1, -1});
    }

    int last = 0;
    for(int i = 1; i < N; i++) 
    {
        for(int j = 0; j < i; j++) 
        {
            if(v[i] > v[j] && dp[i].first < dp[j].first + 1) 
            {
                dp[i].first = dp[j].first + 1;
                dp[i].second = j;
            }
        }
        if(dp[i].first > dp[last].first) last = i;
    }

    vector<int> ans;
    for(int i = last; i != -1; i = dp[i].second) ans.push_back(v[i]);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";

    return 0;
}