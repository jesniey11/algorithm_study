#include<iostream>
#include<queue>
#define INF 999999999

using namespace std;

// Global variables
int N;
int cave[126][126], visit[126][126];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool input() 
{
    cin >> N;
    if(N == 0) return false;
    
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) cin >> cave[i][j];
    }

    return true;
}

void init()
{
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) visit[i][j] = INF;
    }
}

void dijkstra()
{
    priority_queue<pair<pair<int, int>, int>> pq; // {{x, y}, rupee}
    
    pq.push({{0, 0}, -cave[0][0]});
    visit[0][0] = cave[0][0];

    while(!pq.empty())
    {
        int x = pq.top().first.first;
        int y = pq.top().first.second;
        int r = -pq.top().second;
        pq.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || N <= nx || N <= ny) continue;
            
            int nr = r + cave[nx][ny];

            if(nr < visit[nx][ny])
            {
                visit[nx][ny] = nr;
                pq.push({{nx, ny}, -nr});
            }
        }
    }
}

int main()
{
    fastio();
    
    int tc = 1;
    while(true)
    {
        if(!input()) break;
        init();
        dijkstra();

        cout << "Problem " << tc++ << ": " << visit[N-1][N-1] << "\n";
    }

    return 0;
}