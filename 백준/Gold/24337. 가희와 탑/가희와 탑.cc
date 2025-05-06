#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N, a, b;
    cin >> N >> a >> b;

    int apex = max(a, b);
    vector<int> v1, v2;

    for(int i = 1; i <= a; i++) 
    {
        if(i == a) v1.push_back(apex);
        else v1.push_back(i);
    }
    for(int i = b-1; i > 0; i--) v2.push_back(i);

    if(v1.size() + v2.size() > N) 
    {
        cout << -1;
        return 0;
    }

    int cnt = N - (v1.size() + v2.size());
    if(cnt == 0) 
    {
        for(auto au:v1) cout << au << " ";
        for(auto au:v2) cout << au << " ";
    }
    else 
    {
        if(a <= 1)
        {
            for(auto au:v1) cout << au << " ";
            for(int i = 0; i < cnt; i++) cout << 1 << " ";
            for(auto au:v2) cout << au << " ";
        }
        else 
        {
            for(int i = 0; i < cnt; i++) cout << 1 << " ";
            for(auto au:v1) cout << au << " ";
            for(auto au:v2) cout << au << " ";
        }
    }

    return 0;
}