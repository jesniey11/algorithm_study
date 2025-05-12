#include<iostream>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    int P;
    cin >> P;

    for(int p = 0; p < P; p++) 
    {
        int tnum, arr[20], ans = 0;

        cin >> tnum;
        for(int i = 0; i < 20; i++) cin >> arr[i];

        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(arr[i] < arr[j]) 
                {
                    int tmp = arr[i];
                    for(int k = i; k > j; k--) 
                    {
                        arr[k] = arr[k-1];
                        ans++;
                    }
                    arr[j] = tmp;

                    break;
                }
            }
        }

        cout << tnum << " " << ans << "\n";
    }    
    return 0;
}