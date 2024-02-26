#include <iostream>
using namespace std;

#define MAX 999999999;
int N,M;
int map[1001][1001];
int d[1001][1001][3];

int Dp(int x,int y, int pre){
    if(x <= 0 || x > N || y <= 0 || y > M) return MAX;
    if(d[x][y][pre] < 999999999) return d[x][y][pre];

    int val = MAX;

    switch(pre){
        case 0:
        val = map[x][y] + min(Dp(x-1,y,1),Dp(x-1,y+1,2));
        break;
        case 1:
        val = map[x][y] + min(Dp(x-1,y-1,0),Dp(x-1,y+1,2));
        break;
        case 2:
        val = map[x][y] + min(Dp(x-1,y-1,0),Dp(x-1,y,1));
        break;
    }
    return d[x][y][pre] = val;
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    
    cin >> N >> M;

    for(int i = 0; i < 1001; i++)
        for(int j = 0; j< 1001; j++)
            for(int k = 0; k <= 2; k++) {
                d[i][j][k] = MAX;
                map[i][j] = MAX;
        }
    for(int i = 1; i<= N; i++)
        for(int j = 1; j<=M; j++) {
            cin >> map[i][j];
            if(i == 1) {
                d[1][j][0] = map[i][j];
                d[1][j][1] = map[i][j];
                d[1][j][2] = map[i][j];
            }
        }
    int ans = MAX;

    for(int j = 1; j <= M; j++){
        for(int i = 0; i<=2; i++){
            ans = min(ans,Dp(N,j,i));
        }
    }
    cout << ans;
}