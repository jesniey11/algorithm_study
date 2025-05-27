#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    int N, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int n; cin >> n;
        pq.push(n);
    }

    while(pq.size() > 1)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        ans += a+b;
        pq.push(a+b);
    }

    cout << ans;
    return 0;
}