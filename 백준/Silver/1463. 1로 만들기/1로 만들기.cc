//BFS
#include<iostream>
#include<queue>

#define MAX 1000001

using namespace std;

int N, m = 999999999;
queue<pair<int, int>> q;
bool visit[MAX];

void BFS()
{
    q.push({N, 0});
    visit[N] = true;
    
    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();

        if(p.first == 1) 
        {
            m = min(m, p.second);
            return;
        }

        for(int i = 0; i < 3; i++)
        {
            int nx = p.first;

            switch (i)
            {
                case 0: 
                    if(nx % 3 == 0) nx /= 3; break;

                case 1: 
                    if(nx % 2 == 0) nx /= 2; break;

                case 2: 
                    nx--; break;
            }

            if(nx < 1 || MAX <= nx || visit[nx]) continue;
            
            q.push({nx, p.second+1});
            visit[nx] = true;
        }
    }
}

int main()
{
    cin >> N;
    BFS();

    cout << m;
    return 0;
}