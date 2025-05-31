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
    int T, N, ans;
    string num, mine;
    cin >> T;

    while(T--)
    {
        cin >> N;
        cin >> num >> mine;
        ans = 0;

        for(int i = 0; i < N; i++) 
        {
            bool flag = true;
            
            for(int n = i-1; n <= i+1; n++)
            {
                if(n < 0 || n >= N) continue;
                if(num[n] == '0') flag = false;
            }

            if(flag)
            {
                for(int n = i-1; n <= i+1; n++)
                {
                    if(n < 0 || n >= N) continue;
                    num[n]--;
                }

                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}