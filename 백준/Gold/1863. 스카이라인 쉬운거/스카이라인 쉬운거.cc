#include<iostream>
#include<stack>
#define MAX 1000001

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;

    stack<int> sky;
    for(int i = 0; i < n; i++) 
    {
        int x, y;
        cin >> x >> y;

        while(!sky.empty() && y <= sky.top() )
        {
            if(y != sky.top()) ans++;
            sky.pop();
        }

        sky.push(y);
    }

    while(!sky.empty()) 
    {
        if(sky.top()) ans++;
        sky.pop();
    }

    cout << ans;
    return 0;
}