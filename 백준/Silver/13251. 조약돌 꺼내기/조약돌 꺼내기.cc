#include <iostream>
using namespace std;
int main() 
{
	int m, k;
	int total = 0;
	double ans = 0.0;
	double tmp;
	int color[51];

	cin >> m;
	for(int i = 0; i < m; i++) 
	{ 
		cin >> color[i];
		total += color[i];
	}
	cin >> k;


	for (int i = 0; i < m; i++) 
	{
		if (color[i] < k) { continue; }

		tmp = 1.0;
		for (int j = 0; j < k; j++) { tmp *= (color[i] - j); }
		ans += tmp;
	}

	tmp = 1;
	for (int i = total; i > total - k; i--) { tmp *= i; }

	cout << fixed;
	cout.precision(15);
	cout << ans/tmp;
}