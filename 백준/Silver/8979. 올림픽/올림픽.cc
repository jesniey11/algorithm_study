#include<iostream>

using namespace std;

int main()
{
    int N, K, arr[1001][3];
    cin >> N >> K;

    for(int i = 0; i < N; i++) 
    {
        int num;
        cin >> num >> arr[num][0] >> arr[num][1] >> arr[num][2];
    }

    int rank = 1;
    for(int i = 1; i <= N; i++) 
    {
        if(arr[K][0] < arr[i][0]) rank++;
        else if(arr[K][0] == arr[i][0] && arr[K][1] < arr[i][1]) rank++;
        else if(arr[K][0] == arr[i][0] && arr[K][1] == arr[i][1] && arr[K][2] < arr[i][2]) rank++;
    }

    cout << rank;
    return 0;
}