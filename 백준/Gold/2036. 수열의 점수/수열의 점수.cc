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
    fastio();
    
    int N;
    long long ans = 0;
    vector<long long> v;

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        long long n; cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int i = 0;
    while(i+1 < N && v[i] <= 0) 
    {
        if(v[i+1] <= 0)
        {
            ans += v[i] * v[i+1];
            i += 2;
        }
        else
        {
            ans += v[i];
            i++;
        }
    }
    if (i < N && v[i] < 0) ans += v[i];

    int j = N-1;
    while(j > 0 && v[j] > 0) 
    {
        if(v[j-1] > 1)
        {
            ans += v[j] * v[j-1];
            j -= 2;
        }
        else
        {
            ans += v[j];
            j--;
        }
    }
    if (j == 0 && v[j] > 0) ans += v[j];

    cout << ans;
    return 0;
}