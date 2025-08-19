#include<iostream>
#include<algorithm>

using namespace std;

string str[5], ans = "";
int maxl = 0;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    for(int i = 0; i < 5; i++) 
    {
        cin >> str[i];
        int len = str[i].size();
        maxl = max(maxl, len);
    }

    int idx = 0;
    for(int i = 0; i < maxl; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i < str[j].size()) ans += str[j][i];
        }
    }

    cout << ans;
    return 0;
}