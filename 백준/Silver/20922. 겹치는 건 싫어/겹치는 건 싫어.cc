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
        //cout << "i: " << i << " arr[i]: " << arr[i] << "\n";
    }

    int start = 1, end = 1;

     while(start <= end && end < n)
    {
        //cout << "cnt[" << arr[end] << "]: " << cnt[arr[end]] << "\n";

        if(cnt[arr[end]] < k) 
        {
            cnt[arr[end++]]++;
            ans = max(ans,(end-start));
        }

        else if(cnt[arr[end]] == k)
        {
            cnt[arr[start++]]--;
        }
    }

    cout << ans;

    return 0;
}