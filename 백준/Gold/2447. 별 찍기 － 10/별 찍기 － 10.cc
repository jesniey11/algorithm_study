#include<iostream>
#include<cstring>

using namespace std;

int N;
char arr[2200][2200];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void star(int y, int x, int n)
{
    if((y/n) % 3 == 1 && (x/n) % 3 == 1) arr[y][x] = ' ';
    else if(n/3 == 0) arr[y][x] = '*';
    else star(y, x, n/3);
}

int main()
{
    fastio();
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) star(i, j, N);
    }

    for(int i = 0; i < N; i++) cout << arr[i] << "\n";
    return 0;
}