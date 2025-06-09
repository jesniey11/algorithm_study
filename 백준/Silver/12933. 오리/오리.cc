#include<iostream>
#include<vector>

using namespace std;
int main()
{
    string duck, quack = "quack";
    cin >> duck;

    int size = duck.size(), ans = 0, cnt = 0;
    vector<bool> visit(size);

    if(size % 5 != 0 || duck[0] != 'q') 
    {
        cout << -1;
        return 0;
    }

    int t = 1;
    while(true) 
    {
        if(cnt == size) break;

        int qidx = 0, qcnt = 0;
        for(int i = 0; i < size; i++) 
        {
            if(visit[i] || duck[i] != quack[qidx]) continue;
            qidx = (qidx+1) % 5;
            visit[i] = true; qcnt++;
        }

        // 예외 1: qua 하고 울기 (qidx != 0)
        // 예외 2: 아예 울지도 않았음 (qcnt == 0) -> 이 경우에도 qidx = 0 이므로
        if(qidx != 0 || qcnt == 0) 
        {
            cout << -1;
            return 0;
        }

        cnt += qcnt;
        ans++;
    }
    
    cout << ans;
    return 0;
} 