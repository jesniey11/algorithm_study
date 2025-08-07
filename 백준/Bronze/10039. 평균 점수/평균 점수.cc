#include<iostream>

using namespace std;

int score, sum;

int main()
{
    for(int i = 0; i < 5; i++)
    {
        cin >> score;
        if(score < 40) score = 40;

        sum += score;
    }

    cout << sum/5;
    return 0;
} 