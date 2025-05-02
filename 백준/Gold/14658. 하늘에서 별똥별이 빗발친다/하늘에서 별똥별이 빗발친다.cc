#include<iostream>
#include<vector>

using namespace std;

int N, M, L, K, ans = 0;
vector<pair<int, int>> meteor;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    cin >> N >> M >> L >> K;
    for(int k = 0; k < K; k++)
    {
        int n, m;
        cin >> n >> m;

        meteor.push_back({n, m});
    }

    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < K; j++) 
        {
            int cnt = 0;
            int x = meteor[i].first;
            int y = meteor[j].second;

            for(auto& a : meteor)
            {
                int targetX = a.first, targetY = a.second;
                if(x <= targetX && targetX <= x+L && y <= targetY && targetY <= y+L) cnt++;
            }

            ans = max(ans, cnt);
        }        
    }

    cout << K-ans;
    return 0;
}