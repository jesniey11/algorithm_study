#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int N, M, idx = 1, ans = 0;
deque<int> dq;

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> N >> M;
    for(int i = 1; i <= N; i++) dq.push_back(i);

    for(int i = 0; i < M; i++) 
    {
        int n; 
        cin >> n;

        idx = find(dq.begin(), dq.end(), n) - dq.begin();
        while(dq.front() != n) 
        {
            if(idx < dq.size() - idx)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else 
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        dq.pop_front();
    }
    
    cout << ans;
    return 0;
}