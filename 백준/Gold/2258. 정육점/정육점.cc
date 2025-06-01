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

bool wdsc_casc(pair<int, int> &a, pair<int, int> &b)
{
    if(a.second == b.second) return a.first > b.first;
    else return a.second < b.second;
}

int main()
{
    int N, M;
    vector<pair<int, int>> v; // {무게, 금액}
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        int w, c; 
        cin >> w >> c;
        v.push_back({w, c});
    }

    sort(v.begin(), v.end(), wdsc_casc);

    int cost = -1, csum = 0, wsum = 0;
    for(int i = 0; i < N; i++) 
    {
        if(wsum < M) 
        {
            if(cost == v[i].second) csum += v[i].second;
            else 
            {
                cost = v[i].second;
                csum = v[i].second;
            }
        }
        else
        {
            if ((cost != v[i].second) && (csum >= v[i].second))
			{
				cost = v[i].second;
                csum = v[i].second;
			}
        }

        wsum += v[i].first;
    }
    
    if(wsum < M) cout << -1;
    else cout << csum;
    return 0;
}