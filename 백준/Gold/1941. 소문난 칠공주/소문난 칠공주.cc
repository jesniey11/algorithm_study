#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int ans = 0;
char arr[5][5];
bool mask[25];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void fastin()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
}

void BFS(int dasom, int cnt)
{
    queue<pair<int, int>> q;
    bool visit[5][5] = {}, princess[5][5] = {};

    for(int i = 0; i < 25; i++)
    {
        if(mask[i]) continue;

        int y = i/5;
        int x = i%5;
        princess[y][x] = true;
        
        if(q.empty())
        {
            q.push({y, x});
            visit[y][x] = true;
        }
    }

    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();
        
        cnt++;
        if(arr[p.first][p.second] == 'S') dasom++;

        for(int i = 0; i < 4; i++) 
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            
            if(ny < 0 || nx < 0 || 5 <= ny || 5 <= nx) continue;
            if(visit[ny][nx] || !princess[ny][nx]) continue;

            q.push({ny, nx});
            visit[ny][nx] = true;
        }
    }

    if(dasom >= 4 && cnt == 7) ans++;
}

int main()
{
    fastin();
    for(int i = 0; i < 5; i++) cin >> arr[i];
    
    fill(mask + 7, mask + 25, true);
    do BFS(0, 0);
    while (next_permutation(mask, mask + 25));

    cout << ans;
    return 0;
}