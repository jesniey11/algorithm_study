#include <iostream>
#include <vector>

using namespace std;

void fastio() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	fastio();

	int n, m, p;
	cin >> n >> m;

	vector<string> title(n);
	vector<int> power(n);

	for (int i = 0; i < n; i++) { cin >> title[i] >> power[i]; }

	int low, high, mid;

	for (int i = 0; i < m; i++) 
	{
		low = 0;
		high = n - 1;
		cin >> p;
		while (low <= high) 
		{
			mid = (low + high) / 2;
			if (p <= power[mid]) { high = mid - 1; }
			else { low = mid + 1; }
		}

		if (p > power[mid]) { mid += 1; }
		cout << title[mid] << "\n";
	}

	return 0;
}