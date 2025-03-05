#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main() 
{
    int n, d, k, c;
    int ans = 0;
    cin >> n >> d >> k >> c;

    vector<int> sushi(n);
    for(int i = 0; i < n; i++) cin >> sushi[i];

    for(int i = 0; i < n; i++)
    {
        vector<int> menu(3001);
        
        int cnt = 0; // 중복으로 먹은 초밥 숫자
        bool coupon = true; // 레일에 없거나 연속에 포함되지 않으면 추가 초밥 1개

        for (int j = i; j < i+k; j++)
        {
            if(menu[sushi[j%n]] != 0) cnt++;
            else menu[sushi[j%n]]++;

            if(sushi[j%n] == c) coupon = false;
        }

        ans = max(ans, k-cnt+coupon);
    }
    
    cout << ans;

    return 0;
}