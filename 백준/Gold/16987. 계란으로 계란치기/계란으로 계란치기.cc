#include<iostream>
#include<vector>

using namespace std;

int N, d, w;
int ans = 0, cnt = 0;
vector<pair<int, int>> egg;

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve(int now)
{
    if(now == N) 
    {
        ans = max(ans, cnt);
        return;
    }

    if(egg[now].first <= 0 || cnt == N-1) 
    {
        solve(now+1);
        return;
    }

    for(int i = 0; i < N; i++)
    {
        if(i == now || egg[i].first <= 0) continue;

        egg[now].first -= egg[i].second;
        egg[i].first -= egg[now].second;

        if(egg[now].first <= 0) cnt++;
        if(egg[i].first <= 0) cnt++;

        solve(now+1);

        if(egg[now].first <= 0) cnt--;
        if(egg[i].first <= 0) cnt--;

        egg[now].first += egg[i].second;
        egg[i].first += egg[now].second;
    }
}

int main()
{
    fastin();

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> d >> w;
        egg.push_back({d, w});
    }

    solve(0);

    cout << ans;
    return 0;
}