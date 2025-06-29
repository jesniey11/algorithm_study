#include<iostream>

using namespace std;

int N, e;
int arr[2200][2200], ans[3];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool check(int y, int x, int size)
{
    for(int i = y; i < y+size; i++) 
    {   
        for(int j = x; j < x+size; j++)
        {
            if(arr[y][x] != arr[i][j]) return false;
        }
    }
    return true;
}

void search(int y, int x, int size)
{
    if(check(y, x, size)) 
    {
        ans[arr[y][x]+1]++; return;
    }

    int s = size / 3;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++) search(y+i*s, x+j*s, s);
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) cin >> arr[i][j];
    }    

    search(0, 0, N);

    for(int i = 0; i < 3; i++) 
    {
        cout << ans[i] << "\n";
    }

    return 0;
} 