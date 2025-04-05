#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> s(n);
    vector<int> frequency(10, 0);
    for(int i = 0; i < n; i++)cin >> s[i];

    int l = 0, r = 0, cnt = 1, ans = 0;
    frequency[s[l]]++;

    while(l <= r && r < n){
        if(cnt <= 2){
            ans = max(ans, r - l + 1);
            r++;
            if(!frequency[s[r]])cnt++;
            frequency[s[r]]++;
        }
        else{
            frequency[s[l]]--;
            if(!frequency[s[l]])cnt--;
            l++;
        }
    }

    cout << ans;

    return 0;
}