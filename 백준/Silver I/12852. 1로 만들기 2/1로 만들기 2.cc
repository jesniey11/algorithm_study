#include <iostream>

using namespace std;

int main() 
{
	int n, x;
	cin >> n;
	int num[1000001];
	x = n;

	for (int i = 1; i <= n; i++) { num[i] = i; }

	for (int i = 2; i <= n; i++) 
	{
		if (i % 3 == 0) { num[i] = min(num[i], num[i / 3]); }
		if (i % 2 == 0) { num[i] = min(num[i], num[i / 2]); }
		num[i] = min(num[i], num[i-1]) + 1;
	}

	cout << num[n] - 1 << endl;

	while (x >= 1) 
	{
		cout << x << " ";
		if (num[x] == num[x - 1] + 1) { x--; }
		else if (x % 2 == 0 && num[x] == num[x / 2] + 1) { x /= 2; }
		else if (x % 3 == 0 && num[x] == num[x / 3] + 1) { x /= 3; }
	}

	return 0;
}