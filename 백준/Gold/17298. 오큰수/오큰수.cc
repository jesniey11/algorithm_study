#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
    int N;
    vector<int> A, ans;
    stack<int> stk;

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        int n; cin >> n;
        A.push_back(n);
    }

    for(int i = N-1; i >= 0; i--) 
    {
        while(!stk.empty() && stk.top() <= A[i]) stk.pop();
        
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());

        stk.push(A[i]);
    }

    for(int i = N-1; i >= 0; i--) cout << ans[i] << " ";
    
    return 0;
}