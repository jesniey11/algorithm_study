#include<iostream>
#include<vector>
#include<string>
#define MAX 100001

using namespace std;

int N, ans = MAX;
string nstr, tstr;
bool start[MAX], target[MAX];

void toggle(bool arr[], int x)
{
    if(x > 0) arr[x-1] = arr[x-1] ? false : true;
    arr[x] = arr[x] ? false : true;
    if(x < N-1) arr[x+1] = arr[x+1] ? false : true;
}

void solve(bool flag)
{
    bool now[MAX];
    for(int i = 0; i < N; i++) now[i] = start[i];

    int cnt = 0;

    if(flag) 
    {
        toggle(now, 0);
        cnt++;
    }

    for(int i = 1; i < N; i++)
    {
        if(now[i-1] != target[i-1]) 
        { 
            toggle(now, i);
            cnt++;
        }
    }

    for(int i = 0; i < N; i++) 
    {
        if(now[i] != target[i]) return;
    }

    ans = min(ans, cnt);
}

int main()
{   
    cin >> N >> nstr >> tstr;
    for(int i = 0; i < N; i++)
    {
        start[i] = (nstr.at(i) == '1') ? true : false;
        target[i] = (tstr.at(i) == '1') ? true : false;
    }

    solve(true);
    solve(false);

    if(ans != MAX) cout << ans;
    else cout << -1;
    
    return 0;
}