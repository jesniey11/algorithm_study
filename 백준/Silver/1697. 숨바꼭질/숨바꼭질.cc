#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N, K;
int visit[100001]; // 방문여부 + 몇초에 거기 도착했는지

void BFS(int n)
{
    queue<int> que;
    
    que.push(n);
    visit[n] = 1; // 주의: 시작이 1초 => 다음칸에 도착하는 시간이 출발지점에 저장됨

    while(!que.empty())
    {
        int pos = que.front();
        que.pop();

        if(pos == K) 
        {
            cout << visit[pos]-1;
            break;
        }

        for(int i = 0; i < 3; i++)
        {
            int p;
            if(i == 0) p = pos-1;
            if(i == 1) p = pos+1;
            if(i == 2) p = 2*pos;

            if(0 <= p && p < 100001 && visit[p] == 0)
            {
                visit[p] = visit[pos] + 1;
                que.push(p);
            }
        }
    }
}

int main()
{
    cin >> N >> K;

    BFS(N);    

    return 0;
}