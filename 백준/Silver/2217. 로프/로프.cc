#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N, ans = 0; 
    cin >> N;

    vector<int> v;
    for(int i = 0; i < N; i++) 
    {
        int w; cin >> w;
        v.push_back(w);
    }

    sort(v.begin(), v.end(), greater<>());

    ans = v[0];
    for(int i = 1; i < N; i++) 
    {
        int w = (i+1)*v[i];
        ans = max(ans, w);
    }

    cout << ans;
    return 0;
}