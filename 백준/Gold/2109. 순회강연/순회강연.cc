#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    int n, ans = 0;
    vector<pair<int, int>> v;
    priority_queue<int, vector <int>, greater<int>> pq;
    
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        int p, d; cin >> p >> d;
        v.push_back({d, p});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) 
    {
        pq.push(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
    }

    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    
    cout << ans;
    return 0;
}