#include<iostream>

using namespace std;

int N, M, arr[201][201], plan[1001];
bool visit[201][1001], flag = false;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve(int now, int p)
{
    // now = 지금 위치(어느 도시)
    // p = 몇번째 계획을 진행중인지

    if(visit[now][p]) return;
    visit[now][p] = true;

    if(now == plan[p]) 
    {
        if(p == M-1) 
        {
            flag = true;
            return;
        }

        solve(now, p+1);
    }
    
    for(int next = 1; next <= N; next++) 
    {
        // now 에서 갈 수 없는 도시 제외
        if(arr[now][next] == 0) continue;
        solve(next, p);
    }

    return;
}

int main() 
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++) cin >> arr[i][j];
    }
    for(int i = 0; i < M; i++) cin >> plan[i];
    
    solve(plan[0], 0);

    if(flag) cout << "YES";
    else cout << "NO";

    return 0;
}