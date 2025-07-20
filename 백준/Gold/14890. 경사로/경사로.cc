#include<iostream>
#include<vector>

using namespace std;

int N, L, ans = 0;
int board[101][101];

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

bool slope(vector<int> &v)
{
    int cnt = 1;

    for(int i = 0; i < N-1; i++)
    {
        if(abs(v[i] - v[i+1]) > 1) return false;
        if(v[i] == v[i+1]) cnt++;
        else
        {
            // 지금칸 < 다음칸
            if(v[i] < v[i+1])
            {  
                if(cnt < L) return false;
                cnt = 1;
            }

            // 지금칸 > 다음칸
            if(v[i] > v[i+1])
            {
                if(N <= i+L) return false;
                for(int j = i+1; j <= i+L; j++)
                {
                    if(v[j] != v[i+1]) return false;
                }

                i += L-1;
                cnt = 0;
            }
        }
    }

    return true;
}

int main()
{
    fastin();

    cin >> N >> L;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }

    for(int i = 0; i < N; i++) // 가로
    {
        vector<int> road;
        for(int j = 0; j < N; j++) road.push_back(board[i][j]);
        if(slope(road)) ans++;
    }

    for(int j = 0; j < N; j++) // 세로
    {
        vector<int> road;
        for(int i = 0; i < N; i++) road.push_back(board[i][j]);
        if(slope(road)) ans++;
    }

    cout << ans;
    return 0;
}