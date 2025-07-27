#include<iostream>

#define MAX 999999999 

using namespace std;

int M, N, sum, mini = MAX;
bool arr[10001];

int main()
{
    cin >> M >> N;
    
    arr[0] = arr[1] = true;
    for(int i = 2; i <= N; i++) 
    {
        if(arr[i]) continue;
        for(int j = i*i; j <= N; j+=i)
        {
            if(arr[j]) continue;
            if(j%i == 0) arr[j] = true;
        }
    }

    for(int i = M; i <= N; i++) 
    {
        if(arr[i]) continue;

        mini = min(mini, i);
        sum += i;
    }

    if(mini == MAX) cout << -1;
    else cout << sum << "\n" << mini;
    return 0;
}