#include <iostream>

using namespace std;

int main() 
{
	int n, k, sum;
	string burger;

	cin >> n >> k;
	cin >> burger;

	sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (burger[i] != 'P') { continue; }
		for (int j = i - k; j <= i + k; j++)
		{
			if (burger[j] == 'H')
			{
				sum++;
				burger[j] = 'x';
				break;
			}
		}
	}
	cout << sum;
	return 0;
}