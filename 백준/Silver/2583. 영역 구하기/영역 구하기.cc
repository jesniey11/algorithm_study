#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int M, N, K, num;
int lx, ly, rx, ry;

int arr[101][101], visit[101][101];
queue<pair<int, int>> q;
vector<int> wid;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void BFS(int y, int x)
{
    int cnt = 0;

    q.push({y, x});
    visit[y][x] = true;

    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();
        cnt++;

        for(int i = 0; i < 4; i++)
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(ny < 0 || nx < 0 || M <= ny || N <= nx) continue;
            if(visit[ny][nx] || arr[ny][nx] == 1) continue;

            q.push({ny, nx});
            visit[ny][nx] = true;
        }
    }

    wid.push_back(cnt);
}

int main()
{
    fastin();

    cin >> M >> N >> K;
    for(int k = 0; k < K; k++)
    {
        cin >> lx >> ly >> rx >> ry;
        for(int i = ly; i < ry; i++)
        {
            for(int j = lx; j < rx; j++) arr[i][j] = 1;
        }
    }

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(arr[i][j] == 0 && !visit[i][j])
            {
                BFS(i, j);
                num++;
            }
        }
    }

    sort(wid.begin(), wid.end());

    cout << num << "\n";
    for(int i = 0; i < num; i++) cout << wid[i] << " ";

    return 0;
}