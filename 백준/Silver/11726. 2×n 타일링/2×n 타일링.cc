#include <iostream>

using namespace std;

int main() 
{
	int n;
	cin >> n;

	int* arr = new int[n+1];

	for (int i = 1; i <= n; i++) 
	{
		if (i < 3) { arr[i] = i; }
		else { arr[i] = (arr[i - 1] + arr[i - 2]) % 10007; }
	}

	cout << arr[n];

	return 0;
}