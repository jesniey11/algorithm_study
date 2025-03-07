#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int main()
{
    string s;
    cin >> s;

    int n = s.length();
    int ans = 999999999;
    int anum = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'a') anum++;
    }

    int cnt;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'b') {}

        cnt = 0;
        for(int j = i; j < i+anum; j++)
        {
            if(s[j%n] == 'b') { cnt++; }
        }
        
        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}