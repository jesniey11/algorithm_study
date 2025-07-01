#include<iostream>
#include<cstring>

#define MAX 8000

using namespace std;

int N;
char arr[MAX][MAX];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void triangle(int y, int x)
{
    arr[y][x] = '*';
    arr[y+1][x-1] = arr[y+1][x+1] = '*';
    for(int i = x-2; i <= x+2; i++) arr[y+2][i] = '*';
}

void star(int y, int x, int size)
{
    if(size == 3)
    {
        triangle(y, x);
        return;
    }

    int ns = size / 2;

    star(y, x, ns); // 가운데
    star(y+ns, x-ns, ns); // 왼쪽
    star(y+ns, x+ns, ns); // 오른쪽
}

int main()
{
    fastio();

    cin >> N;

    memset(arr, ' ', sizeof(arr));
    star(0, N-1, N);

    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < (N*2)-1; j++) 
        {   
            if(arr[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}