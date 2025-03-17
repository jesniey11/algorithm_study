#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 999999999

using namespace std;

vector<int> board(101);
vector<bool> visit(101, false);
int N, M;
int ans = MAX;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        board[x] = y;
    }

    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        board[u] = v;
    }
}

int BFS()
{
    queue<pair<int, int>> q; // 위치, 주사위 굴린 횟수
    q.push({1, 0}); // 시작지점

    while(!q.empty())
    {
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for(int i = 1; i <= 6; i++) 
        {
            int p = pos+i;

            if(p == 100) return cnt+1;
            
            if(100 < p || visit[p]) continue;
            if(board[p] != 0) p = board[p];

            q.push({p, cnt+1});
            visit[p] = true;
        }
    }
}

int main()
{
    fastio();
    input();
    
    ans = BFS();

    cout << ans;
    return 0;
}