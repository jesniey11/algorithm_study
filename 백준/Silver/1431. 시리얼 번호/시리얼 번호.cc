#include<iostream>
#include<algorithm>

using namespace std;

int N;
string serial[50];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int cond2(const string &s)
{
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'A') continue;
        sum += s[i] - '0';
    }

    return sum;
}

bool cmp(const string &a, const string &b)
{
    if(a.size() != b.size()) return a.size() < b.size();
    else if(cond2(a) != cond2(b)) return cond2(a) < cond2(b);
    else return a < b;
}

int main()
{
    fastio();

    cin >> N;
    for(int i = 0; i < N; i++) cin >> serial[i];
    
    sort(serial, serial+N, cmp);

    for(int i = 0; i < N; i++) cout << serial[i] << "\n";

    return 0;
}