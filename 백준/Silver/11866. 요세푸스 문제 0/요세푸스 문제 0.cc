#include<iostream>
#include<queue>

using namespace std;

int N, K;
queue<int> q;

void fastout()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
}

int main()
{
    fastout();

    cin >> N >> K;
    for(int i = 1; i <= N; i++) q.push(i);
    
    cout << '<';
    while(!q.empty())
    {
        for(int i = 1; i < K; i++) 
        {
            q.push(q.front()); 
            q.pop();
        }
    
        cout << q.front();
        q.pop();

        if (!q.empty()) cout << ", ";
    }
    cout << '>';

    return 0;
}