#include<iostream>
#include<queue>
#define MAXNODE 1001

using namespace std;

int N, M, ans;
vector<int> node[MAXNODE];
vector<bool> visit(MAXNODE, false);

void BFS(int n)
{
    queue<int> q;
    q.push(n);
    visit[n];

    while(!q.empty()) 
    {
        int now = q.front();
        q.pop();
        
        for(int i = 0; i < node[now].size(); i++)
        {
            int next = node[now][i];
            if(visit[next]) continue;

            visit[next] = true;
            q.push(next);
        }           
    }

    ans++;
    return;
}

int main()
{
    cin >> N >> M;
    ans = 0;

    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        node[u].push_back(v);
        node[v].push_back(u);
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(!visit[i]) BFS(i);
    }

    cout << ans;
    return 0;
}
