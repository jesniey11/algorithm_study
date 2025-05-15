#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    long long ans = 0;
    vector<int> rank;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int r;
        cin >> r;

        rank.push_back(r);
    }

    sort(rank.begin(), rank.end());

    for(int i = 0; i < N; i++) ans += abs(rank[i]-i-1);

    cout << ans;
    return 0;
}