#include<iostream>
#include<cstring>

using namespace std;

int N, ans = 0;
int arr[21][21];

void fastin()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void up()
{
    // i = 0 to N-1
    for(int j = 0; j < N; j++)
    {
        int merge[21] = {0};
        int m = 0;
        for(int i = 0; i < N; i++) 
        {
            if(arr[i][j] == 0) continue;
            
            if(merge[m] == 0) merge[m] = arr[i][j];
            else if(merge[m] == arr[i][j]) merge[m++] *= 2;
            else merge[++m] = arr[i][j];
        }

        for(int i = 0; i < N; i++) arr[i][j] = merge[i];
    }
}

void down()
{
    // i = N-1 to 0
    for(int j = 0; j < N; j++)
    {
        int merge[21] = {0};
        int m = 0;
        for(int i = N-1; i >= 0; i--) 
        {
            if(arr[i][j] == 0) continue;
            
            if(merge[m] == 0) merge[m] = arr[i][j];
            else if(merge[m] == arr[i][j]) merge[m++] *= 2;
            else merge[++m] = arr[i][j];
        }

        for(int i = N-1; i >= 0; i--) arr[i][j] = merge[i];
    }
}

void left()
{
    // j = 0 to N-1
    for(int i = 0; i < N; i++)
    {
        int merge[21] = {0};
        int m = 0;
        for(int j = 0; j < N; j++) 
        {
            if(arr[i][j] == 0) continue;
            
            if(merge[m] == 0) merge[m] = arr[i][j];
            else if(merge[m] == arr[i][j]) merge[m++] *= 2;
            else merge[++m] = arr[i][j];
        }

        for(int j = 0; j < N; j++) arr[i][j] = merge[j];
    }
}

void right()
{
    // j = N-1 to 0
    for(int i = 0; i < N; i++)
    {
        int merge[21] = {0};
        int m = 0;
        for(int j = N-1; j >= 0; j--) 
        {
            if(arr[i][j] == 0) continue;
            
            if(merge[m] == 0) merge[m] = arr[i][j];
            else if(merge[m] == arr[i][j]) merge[m++] *= 2;
            else merge[++m] = arr[i][j];
        }

        for(int j = N-1; j >= 0; j--) arr[i][j] = merge[j];
    }
}

int main()
{
    fastin();

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) cin >> arr[i][j];
    }

    // 방향 5개 고르기(4P5 중복순열)
    for(int n = 0; n < 1024; n++) 
    {
        int cpy[21][21];
        memcpy(cpy, arr, sizeof(arr));

        int dir, d = n;
        for(int i = 0; i < 5; i++)
        {
            dir = d%4;
            d /= 4;
            
            switch (dir)
            {
                case 0: up(); break;
                case 1: down(); break;
                case 2: left(); break;
                case 3: right(); break;
            }
        }

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++) ans = max(ans, arr[i][j]);
        }

        memcpy(arr, cpy, sizeof(arr));
    }

    cout << ans;
    return 0;
}