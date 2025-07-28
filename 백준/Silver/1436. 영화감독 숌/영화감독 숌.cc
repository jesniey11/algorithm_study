#include<iostream>

using namespace std;

int N, ans, cnt, tmp;

int main()
{
    cin >> N;

    while(cnt < N)
    {
        ans++;
        tmp = ans;

        while (tmp != 0)
		{
			if (tmp % 1000 == 666)
			{
				cnt++; break;
			}
			else tmp /= 10;
		}
    }

    cout << ans;
    return 0;
}