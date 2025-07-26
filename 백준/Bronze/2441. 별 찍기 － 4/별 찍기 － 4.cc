#include<iostream>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    
    int N; 
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i; j++) cout << ' ';
        for(int j = i; j < N; j++) cout << '*';

        cout << "\n";
    }

    return 0;
}