#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) 
	{
		int n, m = 0;
		long long money = 0;
		cin >> n;

		vector<int> stock(n);

		for (int i = 0; i < n; i++) { cin >> stock[i]; }

		for (int i = n-1; i >= 0; i--) 
		{
			if (stock[i] > m) { m = stock[i]; }
			else { money += m - stock[i]; }
		}
        
		cout << money << endl;
	}

	return 0;
}