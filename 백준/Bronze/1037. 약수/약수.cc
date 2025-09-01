#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();
    
    int num, x;

    cin >> num;
    vector<int> v;
    
    for(int i = 0; i < num; i++) 
    {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    cout << v[0]*v[num-1];
    
    return 0;
}