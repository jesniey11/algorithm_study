#include<iostream>

using namespace std;

int N, ans = 0;
long long bd[51];

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool isVisible(int i, int j)
{
    int s = min(i, j);
    int e = max(i, j);

    double a = (double)(bd[j]-bd[i])/(j-i);
    double b = bd[i]-(a*i);

    for(int x = s+1; x < e; x++)
    {
        if(bd[x] < (a*x)+b) continue;
        else return false;
    }

    return true;
}

int main()
{
    fastio();
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> bd[i];

    for(int i = 1; i <= N; i++) 
    {
        int cnt = 0;
        for(int j = 1; j <= N; j++)
        {
            if(i == j) continue;
            if(isVisible(i, j)) cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}