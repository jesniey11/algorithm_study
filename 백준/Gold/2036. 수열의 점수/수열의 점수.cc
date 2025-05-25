#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    long long N;
    long long ans = 0;
    vector<long long> v;

    cin >> N;
    for(long long i = 0; i < N; i++) 
    {
        long long n; cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int i = 0;
    while(i + 1 < N && v[i] <= 0) 
    {
        if(v[i] != 0 && v[i+1] <= 0)
        {
            ans += v[i] * v[i+1];
            i++;
        }
        else ans += v[i];
        i++;
    }
    if (i < N && v[i] < 0) ans += v[i];

    i = N-1;
    while(i > 0 && v[i] > 0) 
    {
        if(v[i] > 0 && v[i]+v[i-1] < v[i]*v[i-1])
        {
            ans += v[i] * v[i-1];
            i--;
        }
        else ans += v[i];
        i--;
    }
    if (i == 0 && v[i] > 0) ans += v[i];

    cout << ans;
    return 0;
}