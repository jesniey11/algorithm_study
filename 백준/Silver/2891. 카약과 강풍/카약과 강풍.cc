#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N, S, R, ans = 0;
    cin >> N >> S >> R;

    vector<int> v(N+2);
    for(int i = 0; i < S; i++)
    {
        int s; cin >> s;
        v[s] = -1;
    }
    for(int i = 0; i < R; i++)
    {
        int r; cin >> r;
        v[r]++;
    }

    for (int i = 1; i <= N; i++) 
    {
        if (v[i] > 0) {
            if (v[i-1] == -1) v[i] = v[i-1] = 0;
            else if (v[i+1] == -1) v[i] = v[i+1] = 0;
        }
    }

    for(int i = 1; i <= N; i++) 
    {
        if(v[i] == -1) ans++;
    }

    cout << ans;
    return 0;
}