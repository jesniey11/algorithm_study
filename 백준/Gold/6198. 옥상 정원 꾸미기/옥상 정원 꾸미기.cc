#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int N, arr[80002];
    long long ans = 0;
    stack<int> stk;
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    stk.push(arr[0]);
    for(int i = 1; i < N; i++)
    {
        while(!stk.empty() && arr[i] >= stk.top()) stk.pop();
        ans += stk.size();
        stk.push(arr[i]);
    }

    cout << ans;
    return 0;
}