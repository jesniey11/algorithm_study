//BFS
#include<iostream>
#include<queue>

#define MAX 1000001

using namespace std;

int N;
queue<pair<int, int>> q;
bool visit[MAX];

int BFS()
{    
    q.push({N, 0});
    visit[N] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int d = q.front().second;
        q.pop();

        if(x == 1) return d;

        if(x%3 == 0 && !visit[x/3]) 
        {
            q.push({x/3, d+1});
            visit[x/3] = true;
        }

        if(x % 2 == 0 && !visit[x/2])
        {
            q.push({x/2, d+1});
            visit[x/2] = true;
        }

        if (x-1 > 0 && !visit[x-1]) {
            q.push({x-1, d+1});
            visit[x-1] = true;
        }
    }

    return -1;
}

int main()
{
    cin >> N;
    cout << BFS();

    return 0;
}