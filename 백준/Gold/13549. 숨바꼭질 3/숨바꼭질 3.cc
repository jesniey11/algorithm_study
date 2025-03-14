#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N, K;
bool visit[100001];

void search(int n)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, n});

    while (!pq.empty())
    {
        int time = pq.top().first;
        int p = pq.top().second;
        pq.pop();

        visit[p] = true;

        if(p == K) 
        {
            cout << time;
            return;
        }
        if(0 <= p-1 && !visit[p-1]) pq.push({time+1, p-1});
		if(p+1 < 100001 && !visit[p+1]) pq.push({time+1, p+1});
		if(p*2 < 100001 && !visit[p*2]) pq.push({time, p*2});
    }
    
}

int main()
{
    cin >> N >> K;
    search(N);
   
    return 0;
}
