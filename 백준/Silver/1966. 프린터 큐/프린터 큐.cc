#include<iostream>
#include<queue>

using namespace std;

int T;
int N, M, x, ans;

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> T;
    while(T--) 
    {
        queue<pair<int, int>> q;
        priority_queue<int> pq; 

        cin >> N >> M;        
        for(int i = 0; i < N; i++) 
        {
            cin >> x;
            q.push({x, i});
            pq.push(x);
        }

        ans = 1;
        while(true)
        {
            pair<int, int> p = q.front(); q.pop();

            if(p.first != pq.top()) q.push(p);
            else
            {
                if(p.second == M) break;
                pq.pop(); ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}