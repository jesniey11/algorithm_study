#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
int main()
{
    int n, k, ans;
    cin >> n >> k;
    
    n++;
    ans = 0;

    vector<int> arr(n), cnt(100000);
    for(int i=1; i<n; i++)
    {
        cin >> arr[i];
    }

    int start = 1, end = 1;

     while(start <= end && end < n)
    {
        if(cnt[arr[end]] >= k) 
        {
            cnt[arr[start]]--;
            start++;
        }

        else 
        {
            cnt[arr[end]]++;
            end++;
            
            ans = max(ans,(end-start));
        }
    }

    cout << ans;

    return 0;
}