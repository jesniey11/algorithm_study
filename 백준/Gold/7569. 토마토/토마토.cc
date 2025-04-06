#include<iostream>
#include<queue>

using namespace std;

int M, N, H, ans;
int box[101][101][101];

queue<pair<int, pair<int, int>>> q;
int dn[] = {0, 0, 0, 0, -1, 1};
int dm[] = {0, 0, -1, 1, 0, 0};
int dh[] = {-1, 1, 0, 0, 0, 0};

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void BFS()
{    
    while(!q.empty())
    {
        int nn = q.front().second.first;
        int nm = q.front().second.second;
        int nh = q.front().first;
        q.pop();

        for(int i = 0; i < 6; i++)
        {
            int tn = nn + dn[i];
            int tm = nm + dm[i];
            int th = nh + dh[i];

            if(tn < 0 || tm < 0 || th < 0 || N <= tn || M <= tm || H <= th) continue;
            if(box[th][tn][tm] == 0) 
            {
                box[th][tn][tm] = box[nh][nn][nm] + 1;
                q.push({th, {tn, tm}});
            }
        }
    }

}

int check()
{
    int cnt = 0;

    for(int k = 0; k < H; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(box[k][i][j] == 0) return 0;
                else cnt = max(cnt, box[k][i][j]);
            }
        }
    }

    return cnt;
}

int main()
{
    fastio();
    cin >> M >> N >> H;
    ans = 0;

    for(int k = 0; k < H; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                cin >> box[k][i][j];
                if(box[k][i][j] == 1) q.push({k, {i, j}});
            }
        }
    }

    BFS();
    cout << check()-1;

    return 0;
}