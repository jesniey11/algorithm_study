#include<iostream>

using namespace std;

int tc;
int x1, y1, r1, x2, y2, r2, ans;

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> tc;
    while(tc--)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ans = 0;
        
        if(x1 == x2 && y1 == y2)
        {
            if(r1 == r2) ans = -1;
            else ans = 0;
        }
        else 
        {
            int pos = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            int rout = (r1+r2)*(r1+r2), rin = (r1-r2)*(r1-r2);

            if(pos > rout || pos < rin) ans = 0;
            else if(pos == rout || pos == rin) ans = 1;
            else ans = 2;
        }

        cout << ans << "\n";
    }
    
    return 0;
}