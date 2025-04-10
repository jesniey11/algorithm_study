#include<iostream>

using namespace std;

int main()
{
    int H, W, ans = 0, board[501];
    cin >> H >> W;

    for(int i = 0; i < W; i++) cin >> board[i];

    for(int t = 1; t < W-1; t++) 
    {
        int s = 0, e = 0;
        for(int j = 0; j < t; j++) s = max(s, board[j]);
        for(int j = t+1; j < W; j++) e = max(e, board[j]);
        ans += max(0, min(s, e)-board[t]);
    }

    cout << ans;

    return 0;
}