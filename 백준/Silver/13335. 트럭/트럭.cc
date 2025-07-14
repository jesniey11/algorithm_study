#include<iostream>
#include<queue>

using namespace std;

int n, w, L, ans = 0;
int arr[1001];
queue<int> q;

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastin();

    cin >> n >> w >> L;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int sum = 0, idx = 0;
    for(int i = 0; i < w; i++) q.push(0);
    
    while(!q.empty() || idx < n)
    {
        ans++;

        sum -= q.front();
        q.pop();

        if(idx < n) 
        {
            if(sum + arr[idx] > L) q.push(0);
            else
            {
                q.push(arr[idx]);
                sum += arr[idx];
                idx++;
            }
        }
    }

    cout << ans;
    return 0;
}