#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool lg(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second || (a.second == b.second && a.first > b.first);
}

int main()
{
    fastio();

    int N;
    long long ans, total = 0, sum = 0;
    cin >> N;

    vector<pair<long long, long long>> v;
    for(int i = 0; i < N; i++) 
    {
        long long x, a;
        cin >> x >> a;
        total += a;

        v.push_back({a, x});
    }

    sort(v.begin(), v.end(), lg);
    for(int i = 0; i < N; i++) 
    {
        sum += v[i].first;
        if(sum >= (total+1)/2) 
        {
            ans = v[i].second; break;
        }
    }

    cout << ans;
    return 0;
}
