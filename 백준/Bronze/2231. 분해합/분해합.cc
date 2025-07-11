#include<iostream>

using namespace std;

int N;
int sum, tmp;

int main()
{
    cin >> N;

    for(int i = 1; i < N; i++) 
    {
        sum = tmp = i;

        while(tmp > 0)
        {
            sum += tmp%10;
            tmp /= 10;
        }

        if(N == sum) 
        {
            cout << i; 
            return 0;
        }
    }

    cout << 0;
    return 0;
}