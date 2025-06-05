#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}

int main()
{
    int N, M, cost[11];
    string ans = "";
    vector<pair<int, int>> v;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> cost[i];
        v.push_back({cost[i], i});
    }
    cin >> M;

    sort(v.begin(), v.end(), comp);

    int price = v[0].first, num = v[0].second;
    if(num == 0) 
    {
        if(N <= 1 || M < v[1].first) 
        {
            cout << 0;
            return 0;
        }

        ans += v[1].second+'0';
        M -= v[1].first;
    }

    while(M >= price)
    {
        ans += num+'0';
        M -= price;
    }

    for(int i = 0; i < ans.size(); i++) 
    {
        int now = ans[i]-'0';
        for(int j = N-1; j >= 0; j--)
        {
            if(j <= now) continue;
            int diff = cost[j] - cost[now];

            if(diff <= M)
            {
                M -= diff;
                ans[i] = j+'0';
                break;
            }
        }
    }

    cout << ans;
    return 0;
}
