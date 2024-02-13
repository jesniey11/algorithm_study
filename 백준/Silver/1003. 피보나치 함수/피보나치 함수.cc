#include <iostream>

using namespace std;

int main() 
{
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) 
	{
		int n;
		cin >> n;
	
		int fibo[41][2];

		fibo[0][0] = 1;
		fibo[0][1] = 0;

		fibo[1][0] = 0;
		fibo[1][1] = 1;

		for (int i = 2; i <= n; i++) 
		{
			fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
			fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
		}

		cout << fibo[n][0] << " " << fibo[n][1] << endl;
	}
    
	return 0;
}