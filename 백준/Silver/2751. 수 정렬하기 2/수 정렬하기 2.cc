#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<int> v;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int n; cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());
    
    for(auto a:v) cout << a << "\n";
    
    return 0;
}