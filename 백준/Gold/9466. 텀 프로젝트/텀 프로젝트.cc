#include<iostream>
#include<cstring>

using namespace std;

int T, n, cnt;
int arr[100001];
int visit[100001];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void init()
{
    memset(visit, 0, sizeof(visit));
    cnt = 0;
}

void DFS(int x)
{
    visit[x] = 1;
    int next = arr[x];

    if(visit[next] == 0) DFS(next);
    else if(visit[next] == 1)
    {
        int a = next;
        while(a != x)
        {
            cnt++;
            a = arr[a];
        }
        cnt++;
    }
    visit[x] = 2;
}

int main()
{
    fastio();

    cin >> T;
    while(T--)
    {
        init();

        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];

        for(int i = 1; i <= n; i++) 
        {
            if(visit[i] == 0) DFS(i);
        }
        
        cout << n - cnt << "\n";
    }

    return 0;
}