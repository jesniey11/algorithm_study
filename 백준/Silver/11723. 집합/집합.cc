#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int M;
set<int> S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
    for(int i = 0; i < M; i++)
    {
        string cmd;
        int x;
        cin >> cmd;

        if(cmd == "all") 
        {
            S = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
            continue;
        }

        if(cmd == "empty")
        {
            S = {};
            continue;
        }

        cin >> x;
        
        if(cmd == "add")
        {
            S.insert(x);
            continue;
        }

        set<int>::iterator it = S.find(x);

        if(cmd == "remove")
        {
            if(it == S.end()) continue;
            else S.erase(it);
        }

        if(cmd == "check")
        {
            if(it == S.end()) cout << 0 << "\n";
            else cout << 1 << "\n";
        }

        if(cmd == "toggle")
        {
            if(it == S.end()) S.insert(x);
            else S.erase(it);
        }
    }
}