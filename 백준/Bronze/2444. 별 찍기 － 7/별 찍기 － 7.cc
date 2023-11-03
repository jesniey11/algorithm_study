#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= 2 * n - 1; i++) 
	{
		if (i != n) 
		{
			for (int j = abs(n-i); j > 0; j--)
			{
				cout << " ";
			}
		}
		
		if (i <= n) 
		{
			for (int j = 1; j <= 2 * i - 1; j++)
			{
				cout << "*";
			}
		}

		else 
		{
			for (int j = 1; j <= 2 * ((2*n) - i) - 1; j++)
			{
				cout << "*";
			}
		}
		

		cout << "\n";
	}

	return 0;
}