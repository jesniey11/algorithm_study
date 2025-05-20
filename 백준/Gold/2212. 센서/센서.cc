#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N, K, ans = 0;
    vector<int> v, dist;

    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        int n; cin >> n;
        v.push_back(n);
    }
    
    sort(v.begin(), v.end());
    for(int i = 0; i < N-1; i++) dist.push_back(v[i+1] - v[i]);
    
    sort(dist.begin(), dist.end(), greater<int>());
    for(int i = K-1; i < dist.size(); i++) ans += dist[i];

    cout << ans;
    return 0;
}