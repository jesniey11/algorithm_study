#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 999999999

using namespace std;

int N, M, ans = MAX;
int city[51][51];
vector<pair<int, int>> house, chicken;

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> N >> M;
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) 
        {
            cin >> city[i][j];
            if(city[i][j] == 1) house.push_back({i, j});
            if(city[i][j] == 2) chicken.push_back({i, j});
        }
    }

    vector<bool> mask(chicken.size(), 1);
    fill(mask.begin(), mask.begin() + M, 0);

    do
    {
        int cdist = 0;
        for(auto a:house)
        {
            int hdist = MAX;
            for(int i = 0; i < chicken.size(); i++)
            {
                if(mask[i]) continue;
                hdist = min(hdist, abs(a.first - chicken[i].first) + abs(a.second - chicken[i].second));
            }

            cdist += hdist;            
        }

        ans = min(ans, cdist);
    }
    while (next_permutation(mask.begin(), mask.end()));

    cout << ans;
    return 0;
}