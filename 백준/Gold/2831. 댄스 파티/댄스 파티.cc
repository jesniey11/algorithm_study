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

int solve(vector<int> &pos, vector<int> &neg)
{
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end(), greater<int>());

    int p = 0, n = 0, cnt = 0;
    while(p < pos.size() && n < neg.size()) 
    {
        if(pos[p] < neg[n]) 
        {
            cnt++;
            p++; n++;
        }
        else p++;
    }

    return cnt;
}

int main()
{
    fastio();

    int N;
    vector<int> pman, pwoman, nman, nwoman;

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        int m; cin >> m;
        if(m > 0) pman.push_back(m);
        if(m < 0) nman.push_back(-m);
    }

    for(int i = 0; i < N; i++) 
    {
        int w; cin >> w;
        if(w > 0) pwoman.push_back(w);
        if(w < 0) nwoman.push_back(-w);
    }
    
    cout << solve(pman, nwoman) + solve(pwoman, nman);
    return 0;
}