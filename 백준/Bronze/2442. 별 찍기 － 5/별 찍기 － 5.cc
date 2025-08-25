#include<iostream>

using namespace std;

int N;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N-i; j++) cout << ' ';
        for(int j = 1; j <= (i*2)-1; j++) cout << '*';
        cout << "\n";
    }
    
    return 0;
}