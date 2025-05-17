#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n, m, ans = 0;
    vector<pair<int, int>> subject;
    vector<vector<int>> mileage;
    vector<int> sungjun;

    cin >> n >> m;
    for(int i = 0; i < n; i++) 
    {
        int p, l;
        cin >> p >> l;
        subject.push_back({p, l});

        vector<int> mile(p);
        for(int j = 0; j < p; j++) cin >> mile[j];
        sort(mile.begin(), mile.end());

        mileage.push_back(mile);
    }

    for(int i = 0; i < n; i++)
    {
        int t = subject[i].first - subject[i].second;
        if(t < 0) sungjun.push_back(1);
        else sungjun.push_back(mileage[i][t]);
    }

    sort(sungjun.begin(), sungjun.end());
    for(int i = 0; i < n; i++) 
    {
        m -= sungjun[i];
        if(m >= 0) ans++;
    }

    cout << ans;
    return 0;
}