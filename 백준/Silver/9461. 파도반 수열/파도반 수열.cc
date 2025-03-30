#include<iostream>

using namespace std;
long long pv[101] = {0, 1, 1, 1, 2, };

int main()
{
    int tc;
    cin >> tc;

    for(int t = 0; t < tc; t++)
    {
        int N;
        cin >> N;

        for(int i = 5; i <= N; i++)
        {
            if(pv[i] != 0) continue;
            pv[i] = pv[i-5] + pv[i-1];
        }

        cout << pv[N] << "\n";
    }
    return 0;
}