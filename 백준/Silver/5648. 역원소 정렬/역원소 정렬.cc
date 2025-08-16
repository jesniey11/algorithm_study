#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<long long> v;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        
        v.push_back(stoll(s));
    }
    sort(v.begin(), v.end());
     
    for(auto a:v) cout << a << '\n';

    return 0;
}