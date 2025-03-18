#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        string W;
        int K, ans1, ans2;
        vector<int> alpha[26]; // alpha[a][0] = W-idx

        cin >> W >> K;
        for(int i = 0; i < W.size(); i++) alpha[W.at(i)-97].push_back(i);

        ans1 = 100001;
        ans2 = 0;

        for(int i = 0; i < 26; i++)
        {
            int s = alpha[i].size();

            if(s < K) continue;
            for(int j = 0; j <= s-K; j++)
            {
                ans1 = min(ans1, alpha[i][j+K-1]-alpha[i][j]+1);
                ans2 = max(ans2, alpha[i][j+K-1]-alpha[i][j]+1);
            }
        }

        if(ans1 == 100001 || ans2 == 0) cout << -1 << "\n";
        else cout << ans1 << " " << ans2 << "\n";
    }

    return 0;
}