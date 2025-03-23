#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

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

    int N;
    cin >> N;

    vector<int> coord(N);
    vector<int> v;

    for(int i = 0; i < N; i++)
    {
        cin >> coord[i];
        v.push_back(coord[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for(int i = 0; i < N; i++)
    {
        int x = lower_bound(v.begin(), v.end(), coord[i])-v.begin();
        cout << x << " ";
    }
}