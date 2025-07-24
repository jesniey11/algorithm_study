#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;

int N, age;
string name;
vector<tuple<int, int, string>> v;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> age >> name;
        v.push_back({age, i, name});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++) 
    {
        tuple<int, int, string> t = v[i];
        cout << get<0>(v[i]) << " " << get<2>(v[i]) << "\n";
    }

    return 0;
}