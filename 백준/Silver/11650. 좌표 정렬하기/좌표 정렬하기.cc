#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, x, y;
vector<pair<int, int>> v;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++) cout << v[i].first << " " << v[i].second << "\n";

    return 0;
}