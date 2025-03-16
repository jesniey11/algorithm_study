#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N, K, ans, zero;
deque<pair<int,bool>> belt; // 내구도, 로봇있는지

void testprint(deque<pair<int,bool>> dq)
{
    for(auto v:dq)
    {
        cout << v.first << " " << v.second << "\n";
    }
}

void move(deque<pair<int,bool>> &dq)
{
    for(int i = N-1; i >= 0; i--)
    {
        pair<int,bool> &now = dq.at(i);
        pair<int,bool> &next = dq.at(i+1);

        // 현재위치에 로봇 없음/다음 칸 내구도 0/다음 칸 로봇 있음
        // 이동 불가
        if(!now.second || next.first == 0 || next.second) continue;

        // 로봇 이동
        now.second = false;
        next.first--;
        
        if(i+2 != N) next.second = true;

        // 내구도 0 체크
        if(next.first == 0) zero++;
    }
}

int main()
{
    cin >> N >> K;
    ans = 0; // 단계
    zero = 0; // 0이 몇개인지

    for(int i = 0; i < 2*N; i++)
    {
        int dur;
        cin >> dur;

        belt.push_back({dur, false});
    }

    while(true)
    {       
        ans++;

        // 벨트 회전
        belt.push_front(belt.back());
        belt.pop_back();

        // 벨트 회전으로 로봇이 N에 도달 
        if(belt.at(N-1).second == true) 
        {
            belt.at(N-1).second = false;      
        }

        // 로봇 이동
        move(belt);

        pair<int,bool> &p = belt.front();

        // 로봇 올리기
        if(!p.first == 0) 
        {
            p.first--;
            p.second = true;

            if(p.first == 0) zero++;
        }

        if(K <= zero) break;
    }

    cout << ans;
    return 0;
}