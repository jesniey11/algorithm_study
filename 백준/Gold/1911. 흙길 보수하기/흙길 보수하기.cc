#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N, L, ans = 0;
    vector<pair<int, int>> road;

    cin >> N >> L;
    for(int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;

        road.push_back({s, e});
    }

    sort(road.begin(), road.end());

    int s = road[0].first;
    int e = road[0].first+L;

    for(int i = 0; i < road.size(); i++)
    {
        if(s < road[i].first) 
        {
            s = road[i].first;
            e = road[i].first+L;
        }

        while(s < road[i].second) 
        {
            ans++;
            s = e;
            e = s+L;
        }
    }
    
    cout << ans;
    return 0;
}