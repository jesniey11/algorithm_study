#include<iostream>
#include<queue>

using namespace std;

int K, W, H;
int arr[201][201];

int hy[] = {-1, -2, -2, -1, 1, 2, 2, 1}, hx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

struct ss
{
    int y, x, k, dist;
};

int BFS()
{
    queue<ss> q;
    bool visit[201][201][31];

    q.push({0, 0, 0, 0});
    visit[0][0][0] = true;

    while(!q.empty())
    {
        ss p = q.front(); q.pop();
        
        if(p.y == H-1 && p.x == W-1) return p.dist;

        if(p.k < K) 
        {
            for(int d = 0; d < 8; d++) 
            {
                int ny = p.y + hy[d];
                int nx = p.x + hx[d];
                int nk = p.k + 1;

                if(ny < 0 || nx < 0 || H <= ny || W <= nx) continue;
                if(visit[ny][nx][nk] || arr[ny][nx] == 1) continue;

                q.push({ny, nx, nk, p.dist+1});
                visit[ny][nx][nk] = true;
            }
        }

        for(int d = 0; d < 4; d++) 
        {
            int ny = p.y + dy[d];
            int nx = p.x + dx[d];
            
            if(ny < 0 || nx < 0 || H <= ny || W <= nx) continue;
            if(visit[ny][nx][p.k] || arr[ny][nx] == 1) continue;

            q.push({ny, nx, p.k, p.dist+1});
            visit[ny][nx][p.k] = true;
        }
    }

    return -1;
}

int main()
{
    fastin();

    cin >> K >> W >> H;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++) cin >> arr[i][j];
    }

    cout << BFS();
    return 0;
}