#include<iostream>
#include<queue>
#define MAX 999999999

using namespace std;

int N, M;
vector<pair<int, int>> barn[50001];
int visit[50001];

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int dijkstra(int s)
{
    priority_queue<pair<int, int>> pq;
    pq.push({s, 0});
    visit[s] = 0;

    while(!pq.empty())
    {
        int n = pq.top().first;
        int c = pq.top().second;
        pq.pop();

        if(visit[n] < c) continue;
        for(int i = 0; i < barn[n].size(); i++)
        {
            int next = barn[n][i].first;
            int cow = c + barn[n][i].second;
            
            if(cow < visit[next])
            {
                visit[next] = cow;
                pq.push({next, cow});  
            }       
        }
    }

    return visit[N];
}

int main()
{
    fastio();
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        barn[a].push_back({b, c});
        barn[b].push_back({a, c});
    }

    for(int i = 0; i <= N; i++) visit[i] = MAX;

    cout << dijkstra(1);

    return 0;
}