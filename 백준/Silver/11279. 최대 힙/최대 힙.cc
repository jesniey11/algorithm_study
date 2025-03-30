#include<iostream>
#include<queue>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    
    int N;
    cin >> N;

    priority_queue<int> pq;

    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        if(x != 0) pq.push(x);
        else 
        {
            if(pq.empty()) cout << 0 << "\n";
            else 
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}