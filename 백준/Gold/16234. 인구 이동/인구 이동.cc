#include<iostream>
#include<queue>

using namespace std;

int N, L, R, ans;

int A[51][51];
bool visit[51][51];
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

bool solve(int i, int j)
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> unite;

    int sum = A[i][j];

    q.push({i, j});
    visit[i][j] = true;
    unite.push_back({i, j});

    while (!q.empty())
    {
        int x = q.front().first; 
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || N <= nx || N <= ny || visit[nx][ny]) continue;
            
            int gap = abs(A[x][y] - A[nx][ny]);
            if(L <= gap && gap <= R)
            {
                q.push({nx, ny});
                visit[nx][ny] = true;

                sum += A[nx][ny];
                unite.push_back({nx, ny});
            }
        }
    }

    if(unite.size() == 1) return false;
    for(auto a: unite) A[a.first][a.second] = sum / unite.size(); 
    
    return true;
}

int main()
{
    cin >> N >> L >> R;
    ans = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }

    while(true)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++) visit[i][j] = false;
        }
        
        bool flag = false;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(visit[i][j]) continue;
                if(solve(i, j)) flag = true;
            }
        }

        if(flag) ans++;
        else break;
    }

    cout << ans;
    return 0;
}