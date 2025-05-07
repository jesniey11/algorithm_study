#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int R = 12, C = 6, ans = 0;
char board[12][6];

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool visit[12][6], flag;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++) cin >> board[i][j];
    }
}

void puyo(vector<pair<int, int>> &v)
{
    for(auto a:v) 
    {
        int x = a.first;
        int y = a.second;

        board[x][y] = '.';
    }

    for(int j = 0; j < C; j++) 
    {
        int bt = R-1;
        for(int i = R-1; i >= 0; i--)
        {
            if(board[i][j] != '.') 
            {
                board[bt][j] = board[i][j];
                if(bt != i) board[i][j] = '.';
                bt--;
            }
        }
    }
}

void BFS(int row, int col, char c)
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;

    q.push({row, col});
    v.push_back({row, col});
    visit[row][col] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || R <= nx || C <= ny) continue;
            if(visit[nx][ny] || board[nx][ny] != c) continue;

            q.push({nx, ny});
            v.push_back({nx, ny});
            visit[nx][ny] = true;
        }
    }

    if(4 <= v.size()) 
    {
        puyo(v); 
        flag = true;
    }
}

bool solve()
{
    flag = false;
    memset(visit, 0, sizeof(visit));

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++) 
        {
            if(board[i][j] != '.' && !visit[i][j]) BFS(i, j, board[i][j]);
        }
    }

    return flag;
}

int main()
{
    fastio();
    input();

    while(solve()) ans++;

    cout << ans;
    return 0;
}