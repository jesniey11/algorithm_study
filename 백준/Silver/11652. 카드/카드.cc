#include<iostream>
#include<algorithm>

using namespace std;

int N;
long long card[100001];

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> N;
    for(int i = 0; i < N; i++) cin >> card[i];

    sort(card, card+N);

    int cnt = 1, mcnt = 0;
    long long mnum = 0; 
    for(int i = 1; i < N; i++)
    {
        if(card[i-1] == card[i]) cnt++;
        else 
        {
            if(mcnt < cnt) 
            {
                mcnt = cnt;
                mnum = card[i-1];
            }
            cnt = 1;
        }
    }
    if(mcnt < cnt) mnum = card[N-1];

    cout << mnum;
    return 0;
}