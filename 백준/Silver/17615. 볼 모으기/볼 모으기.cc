#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
    int n;
    int ans = 999999999;

    string ball;
    cin >> n >> ball;

    //공 개수 세기
    int red = 0;
    for(int i = 0; i < n; i++)
    {
        if(ball[i] == 'R') red++;
    }
    int blue = n - red; // 파란공 = 전체공-빨간공

    int cnt;
    bool flag;

    //빨간공 왼쪽
    cnt = 0;
    flag = false;
    for(int i = 0; i < n; i++)
    {
        if(ball[i] == 'B') flag = true;
        if(ball[i] == 'R' && flag) cnt++;
    }
    ans = min(ans, cnt);

    //빨간공 오른쪽
    cnt = 0;
    flag = false;
    for(int i = n-1; i >= 0; i--)
    {
        if(ball[i] == 'B') flag = true;
        if(ball[i] == 'R' && flag) cnt++;
    }
    ans = min(ans, cnt);

    //파란공 왼쪽
    cnt = 0;
    flag = false;
    for(int i = 0; i < n; i++)
    {
        if(ball[i] == 'R') flag = true;
        if(ball[i] == 'B' && flag) cnt++;
    }
    ans = min(ans, cnt);

    //파란공 오른쪽
    cnt = 0;
    flag = false;
    for(int i = n-1; i >= 0; i--)
    {
        if(ball[i] == 'R') flag = true;
        if(ball[i] == 'B' && flag) cnt++;
    }
    ans = min(ans, cnt);

    cout << ans;
}