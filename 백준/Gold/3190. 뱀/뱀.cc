#include <iostream>
#include <deque>


using namespace std;

int N, K, L;
int apple[101][101];
int t[101]; char c[101];

deque<pair<int, int>> snake;
bool mark[101][101];
int dir = 3; // 0 1 2 3 (상 하 좌 우)

int lr[] = {2, 3, 1, 0};
int dr[] = {3, 2, 0, 1};

void input()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 0; i < K; i++) 
    {
        int r, c;
        cin >> r >> c;

        apple[r][c] = 1;
    }

    cin >> L;
    for(int i = 0; i < L; i++) cin >> t[i] >> c[i];
}

int rotate(char cc)
{
    if(cc == 'L') return lr[dir];
    if(cc == 'D') return dr[dir];
    return dir;
}

int solve()
{
    int cnt = 0;
    int idx = 0;
    snake.push_back({1, 1});
    mark[1][1] = true;

    while(!snake.empty())
    {
        if(t[idx] == cnt) 
        {
            //cout << "회전한다" << "\n";
            dir = rotate(c[idx]);
            idx++;
        }

        pair<int, int> head = snake.back();
        pair<int, int> tail = snake.front();

        int nx = head.first, ny = head.second;

        if(dir == 0) nx--;
        else if(dir == 1) nx++;
        else if(dir == 2) ny--;
        else if(dir == 3) ny++;

        cnt++;

        if(nx <= 0 || ny <= 0 || nx > N || ny > N || mark[nx][ny]) 
            return cnt;

        if(apple[nx][ny] != 1) 
        {
            snake.pop_front();
            mark[tail.first][tail.second] = false;
        }
        else
        {
            apple[nx][ny] = 0;
        }

        snake.push_back({nx, ny});
        mark[nx][ny] = true;

        if(idx < L && t[idx] == cnt)
        {
            dir = rotate(c[idx]);
            idx++;
        }

    }

    return cnt;
}

int main()
{
    input();
    cout << solve();

    return 0;
}