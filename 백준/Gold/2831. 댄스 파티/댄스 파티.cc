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

int main()
{
    fastio();

    int N, ans = 0;
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

    sort(pman.begin(), pman.end(), greater<int>());
    sort(pwoman.begin(), pwoman.end(), greater<int>());
    sort(nman.begin(), nman.end(), greater<int>());
    sort(nwoman.begin(), nwoman.end(), greater<int>());

    int m, w;
    // pman x nwoman
    m = 0, w = 0;
    while(m < pman.size() && w < nwoman.size()) 
    {
        if(pman[m] < nwoman[w]) 
        {
            ans++;
            m++; w++;
        }
        else m++;
    }

    // nman x pwoman
    m = 0, w = 0;
    while(m < nman.size() && w < pwoman.size()) 
    {
        if(pwoman[w] < nman[m])
        {
            ans++;
            m++; w++;
        }
        else w++;
    }    

    cout << ans;
    return 0;
}