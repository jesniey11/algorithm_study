#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 999999999

using namespace std;

int R, C;
char board[1001][1001];

int jx, jy; // 지훈 초기 위치
vector<pair<int, int>> firepos; // 불 초기 위치
int jihoon[1001][1001], fire[1001][1001]; // 지훈/불 이동경로

queue<pair<int, int>> q;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    cin >> R >> C;
    
    for(int i = 0; i < R; i++) 
    {
        for(int j = 0; j < C; j++) 
        {
            cin >> board[i][j];
            if(board[i][j] == 'J') jx = i, jy = j;
            if(board[i][j] == 'F') firepos.push_back({i, j});
        }
    }
}

void fsolve()
{
    queue<pair<int, int>> q;
    for (auto &f : firepos) {
        fire[f.first][f.second] = 0;
        q.push(f);
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || R <= nx || C <= ny) continue;
            if (board[nx][ny] == '#' || fire[nx][ny] != -1) continue;

            fire[nx][ny] = fire[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

void jsolve()
{
    queue<pair<int, int>> q;
    memset(jihoon, -1, sizeof(jihoon));
    jihoon[jx][jy] = 0;
    q.push({jx, jy});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || R <= nx || C <= ny) {
                cout << jihoon[x][y] + 1;
                return;
            }

            if (board[nx][ny] == '#' || jihoon[nx][ny] != -1) continue;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= jihoon[x][y] + 1) continue; // 불이 먼저 오거나 동시에 오는 경우

            jihoon[nx][ny] = jihoon[x][y] + 1;
            q.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}

int main()
{
    fastio();
    input();

    memset(fire, -1, sizeof(fire));
    fsolve();
    jsolve();

    return 0;
}