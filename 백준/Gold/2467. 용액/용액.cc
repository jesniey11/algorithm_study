#include<iostream>
#define MAX 9999999999

using namespace std;

int main()
{
    int N, ans1, ans2;
    long long num[100000];
    cin >> N;

    for (int i = 0; i < N; i++) cin >> num[i];

    int l = 0, r = N-1; 
    long long min = MAX;

    while(l < r) 
    {
        int sum = num[l] + num[r];
        if (abs(sum) < min) 
        {
            min = abs(sum);
            ans1 = num[l];
            ans2 = num[r];
        }

        if(sum < 0) l++;
        else if(0 <= sum) r--;
    }

    cout << ans1 << " " << ans2;
    return 0;
}