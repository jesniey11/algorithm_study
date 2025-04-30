#include<iostream>
#include<queue>
#define MAX 999999999;

using namespace std;

int N, M, X, ans = 0;
int dist[1001]; // 학생별 소요시간
vector<pair<int, int>> road[1001]; // [시작점] {소요시간, 끝점}

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int dijkstra(int dept, int arv)
{
    for(int i = 1; i <= N; i++) dist[i] = MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, dept});
    dist[dept] = 0;

    while(!pq.empty())
    {
        int t = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        // 목적지도착
        if(now == arv) return dist[now];

        for(auto a:road[now]) 
        {
            int nt = dist[now] + a.first;
            int next = a.second;

            if(dist[next] > nt)
            {
                dist[next] = nt;
                pq.push({nt, next});
            }
        }
    }
}

int main()
{
    cin >> N >> M >> X;

    for(int i = 0; i < M; i++) 
    {
        int s, e, t;
        cin >> s >> e >> t;
        road[s].push_back({t, e});
    }

    for(int i = 1; i <= N; i++) 
    {
        int party = dijkstra(i, X);
        int home = dijkstra(X, i);
        ans = max(ans, party+home);
    }

    cout << ans;
    return 0;
}