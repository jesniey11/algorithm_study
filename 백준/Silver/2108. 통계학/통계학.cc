#include<iostream>
#include<algorithm>

using namespace std;

int N, x;
int sum, mean, freq, cnt, mode, mn = 9999, mx = -9999;
int arr[500001], med[500001], num[8005];

void fastio()
{
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int main()
{
    fastio();

    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        cin >> x;
        
        arr[i] = med[i] = x;
        sum += x;
        num[x+4000]++;
    }

    // 산술평균
    if(sum < 0) mean = (sum - N/2) / N;
    else mean = (sum + N/2) / N;
    cout << mean << "\n";

    // 중앙값
    sort(med, med+N);
    cout << med[N/2] << "\n";

    // 최빈값
    for(int i = 0; i < N; i++) freq = max(freq, num[arr[i]+4000]);
    for(int i = 0; i < N; i++)
    {
        if(freq == num[med[i]+4000] && mode != med[i])
        {
            cnt++; 
            mode = med[i];
        }
        if(cnt == 2) break;
    }
    cout << mode << "\n";

    // 범위
    for(int i = 0; i < N; i++)
    {
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    cout << mx-mn;

    return 0;
}