#include<iostream>
#include<vector>
#include<cstring>
#define MAX 100001

using namespace std;

int N, sum, ans;
bool dp[MAX];
vector<pair<int, int>> money;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void init()
{
    sum = 0;
    money.clear();
    memset(dp, false, sizeof(dp));
}

void input()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int v, n;
        cin >> v >> n;

        money.push_back({v, n});
        sum += v * n;
    }
}

int solve()
{
    dp[0] = true;
    for(auto a:money)
    {
        for(int i = sum/2; i >= a.first; i--)
        {
            if(dp[i]) continue;
            int now = 0;
            for(int j = 0; j < a.second; j++) 
            {
                now += a.first;
                if(i-now >= 0) dp[i] = dp[i-now];
                if(dp[sum/2]) return 1;
            }
        }
    }

    return dp[sum/2];
}

int main()
{
    fastio();
    
    for(int tc = 0; tc < 3; tc++) 
    {
        init();
        input();
        
        if(sum%2 == 1) ans = 0;
        else ans = solve();

        cout << ans << "\n";
    }

    return 0;
}