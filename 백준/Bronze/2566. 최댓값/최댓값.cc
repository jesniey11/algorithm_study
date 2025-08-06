#include<iostream>

using namespace std;

int arr[9][9];
int ans, x, y;

int main()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++) 
        {
            cin >> arr[i][j];
            
            if(ans <= arr[i][j])
            {
                ans = arr[i][j];
                x = i+1; y = j+1;
            }
        }
    }

    cout << ans << "\n" << x << " " << y;
    return 0;
}