#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N, C, ans = 0;
    vector<int> house;
    cin >> N >> C;

    for(int i = 0; i < N; i++) 
    {
        int x;
        cin >> x;
        house.push_back(x);
    }
    
    sort(house.begin(), house.end());
    int l = 1, r = house[N-1]-house[0];

    while(l <= r)
    {
        int mid = (l+r)/2;
        int cnt = 1;

        int house_A = house[0];
    
        for(int i = 1; i < N; i++) 
        {
            // house_A와 house_B(=house[i]) 간 간격
            if(mid <= house[i]-house_A)
            {
                house_A = house[i];
                cnt++;
            }
        }

        if (cnt < C) r = mid - 1;
		else 
        {
            ans = max(ans, mid);
			l = mid + 1;
        }
    }
    
    cout << ans;
    return 0;
}