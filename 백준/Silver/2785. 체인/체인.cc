#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N, ans = 0;
    vector<int> chain;
    
    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        int l; cin >> l;
        chain.push_back(l);
    }

    sort(chain.begin(), chain.end());

    while(chain.size() > 1)
    {
        chain[chain.size()-2] += chain[chain.size()-1];
        chain[0]--;
        ans++;

        chain.pop_back();

        if(chain[0] == 0) 
        {
            for(int i = 0; i < chain.size(); i++) chain[i] = chain[i+1];
            chain.pop_back();
        }
    }

    cout << ans;
    return 0;
}