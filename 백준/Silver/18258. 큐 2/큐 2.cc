#include<iostream>

using namespace std;

int N, q[2000002];
int s = 0, e = 0;
string cmd;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> cmd;
        if(cmd == "push") cin >> q[e++]; 
        if(cmd == "pop") 
        {
            if(s == e) cout << -1 << "\n";
            else cout << q[s++] << "\n";
        }
        if(cmd == "size") cout << e-s << "\n";
        if(cmd == "empty") 
        {
            if(s == e) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        if(cmd == "front") 
        {
            if(s == e) cout << -1 << "\n";
            else cout << q[s] << "\n";
        }
        if(cmd == "back") 
        {
            if(s == e) cout << -1 << "\n";
            else cout << q[e-1] << "\n";
        }
    }

    return 0;
}