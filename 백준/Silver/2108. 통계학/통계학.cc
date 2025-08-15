#include<iostream>
#include<algorithm>

using namespace std;

int N, sum;
int arr[500001], num[8005];

void fastio()
{
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int average()
{
    if(sum < 0) return (sum - N/2) / N;
    else return (sum + N/2) / N;
}

int median()
{
    sort(arr, arr+N);
    return arr[N/2];
}

int mode()
{
    int freq = 0, cnt = 0, res = 0;

    for (int i = 0; i < 8001; i++) freq = max(freq, num[i]);
    for (int i = 0; i < 8001; i++) 
    {
        if (num[i] == freq) 
        {
            int now = i - 4000; cnt++;
            
            if (cnt == 1) res = now; 
            else if (cnt == 2) return now;
        }
    }
    
    return res;
}

int range()
{
    return arr[N-1] - arr[0];
}

int main()
{
    fastio();

    cin >> N;
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
        sum += arr[i];
        num[arr[i] + 4000]++;
    }

    cout << average() << '\n'; // 산술평균
    cout << median() << '\n'; // 중앙값
    cout << mode() << '\n'; // 최빈값
    cout << range(); // 범위

    return 0;
}