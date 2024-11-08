#include <iostream>
#include <queue>

using namespace std;

void fastio()
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastio();

    long long n, m;
    long long ans;
    priority_queue<long long, vector<long long>, greater<long long>> card;

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        long long t;
        cin >> t;
        card.push(t);
    }

    for(int i=0; i<m; i++)
    {
        long long x, y;

        x = card.top();
        card.pop();

        y = card.top();
        card.pop();

        card.push(x+y);
        card.push(x+y);
    }

    ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += card.top();
        card.pop();
    }

    cout << ans;
    return 0;
}