#include<iostream>
#include<deque>

using namespace std;

int N, x;
string cmd;
deque<int> dq;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastio();

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        cin >> cmd;
        if(cmd == "push_front")
        {
            cin >> x; 
            dq.push_front(x);
        }
        if(cmd == "push_back")
        {
            cin >> x; 
            dq.push_back(x);
        }
        if(cmd == "pop_front")
        {
            if(dq.empty()) cout << -1 << "\n";
            else 
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        if(cmd == "pop_back")
        {
            if(dq.empty()) cout << -1 << "\n";
            else 
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        if(cmd == "size") cout << dq.size() << "\n";
        if(cmd == "empty")
        {
            if(dq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        if(cmd == "front")
        {
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        }
        if(cmd == "back")
        {
            if(dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }
    }

    return 0;
}