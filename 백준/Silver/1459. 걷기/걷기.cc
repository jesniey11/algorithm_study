#include<iostream>

using namespace std;

int main()
{
    long long x, y, w, s, ans = 0;
    cin >> x >> y >> w >> s;

    if(w*2 <= s) ans = (x+y) * w;
    else
    {
        int a = min(x, y), b = max(x, y);
        ans = (a*s);
        
        if(w < s) ans += ((b-a)*w);
        else 
        {
            ans += ((b-a)/2) * (2*s);
            if((b-a) % 2 == 1) ans += w;
        }
    }
    
    cout << ans;
    return 0;
}