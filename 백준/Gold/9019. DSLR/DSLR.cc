#include<iostream>
#include<queue>

using namespace std;

int a, b;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int D(int n)
{
    return (n*2)%10000;
}

int S(int n)
{
    if(n-1 == 0) return 9999;
    else return n-1;
}

int L(int n)
{
    return (n % 1000) * 10 + n / 1000;
}

int R(int n)
{
    return (n % 10) * 1000 + (n / 10);
}

string BFS()
{
    queue<pair<int, string>> q;
    bool visit[10000] = {false, };

    q.push({a, ""});
    visit[a] = true;

    while(!q.empty())
    {
        int num = q.front().first;
        string str = q.front().second;
        q.pop();

        if(num == b) return str;

        //D
        int D = (num*2)%10000;
        if(!visit[D]) 
        {
            visit[D] = true;
            q.push({D, str+"D"});
        }

        //S
        int S = (num-1 < 0) ? 9999 : num-1;
        if(!visit[S]) 
        {
            visit[S] = true;
            q.push({S, str+"S"});
        }

        //L
        int L = (num % 1000) * 10 + num / 1000;
        if(!visit[L]) 
        {
            visit[L] = true;
            q.push({L, str+"L"});
        }

        //R
        int R = (num % 10) * 1000 + (num / 10);
        if(!visit[R]) 
        {
            visit[R] = true;
            q.push({R, str+"R"});
        }
    }
}

int main()
{
    fastio();

    int T;
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        cin >> a >> b;
        cout << BFS() << "\n";
    }

    return 0;
}