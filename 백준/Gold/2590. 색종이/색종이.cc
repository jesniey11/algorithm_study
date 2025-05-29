#include<iostream>

using namespace std;

int main()
{
    int ans = 0, arr[7];
    for(int i = 1; i <= 6; i++) cin >> arr[i];

    // 6
    ans += arr[6];

    // 5
    ans += arr[5];
    arr[1] = max(0, arr[1]-arr[5]*11);

    // 4
    ans += arr[4];
    if(arr[4]*5 < arr[2]) arr[2] -= arr[4]*5;
    else 
    {
        int numof1 = 4 * (arr[4]*5 - arr[2]); // 4*(최대 2의 개수-실제 2의 개수)
        arr[1] = max(0, arr[1]-numof1);
        arr[2] = 0;
    }

    // 3
    ans += arr[3]/4 + 1;

    if(arr[3]%4 == 0) ans--;
    else
    {
        int max1, max2;
        switch (arr[3]%4) 
        {
            case 1: max1 = 7, max2 = 5; break;
            case 2: max1 = 6, max2 = 3; break;
            case 3: max1 = 5, max2 = 1; break;
        }

        if (max2 < arr[2]) arr[1] = max(0, arr[1] - max1);
        else arr[1] = max(0, arr[1] - (4*(max2-arr[2]) + max1));

        arr[2] = max(0, arr[2] - max2);
    }  
    
    // 2
    ans += arr[2]/9 + 1;
    if(arr[2]%9 == 0) ans--;
    else arr[1] = max(0, arr[1] - (36-(4*(arr[2]%9))));

    // 1
    ans += arr[1]/36 + 1;
    if(arr[1]%36 == 0) ans--;

    cout << ans;
    return 0;
}