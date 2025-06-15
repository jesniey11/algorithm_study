#include<iostream>
#include<queue>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int N; cin >> N;

    string cmd;
    queue<int> q;
    for(int i = 0; i < N; i++)
    {
        cin >> cmd;
        if(cmd == "push") 
        {
            int n; cin >> n;
            q.push(n);
        }
        if(cmd == "pop") 
        {
            if(q.empty()) cout << -1 << "\n";
            else 
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        if(cmd == "size") cout << q.size() << "\n";
        if(cmd == "empty") 
        {
            if(q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        if(cmd == "front") 
        {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        if(cmd == "back") 
        {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }

    return 0;
}