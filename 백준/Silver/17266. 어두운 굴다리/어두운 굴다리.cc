#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int n, m, x;
	cin >> n >> m;

	vector<int> lamp(m);

	for (int i = 0; i < m; i++) 
	{
		cin >> x; 
		lamp[i] = x;
	}

	int low = 1;
	int high = n;
	int ans = 0;
	bool flag;

	while (low <= high) 
	{
		int mid = (low + high) / 2;
		int prev = 0;
		flag = false;
		
		for (int i = 0; (i < m) && (!flag); i++) 
		{

			if (lamp[i] - mid <= prev) { prev = lamp[i] + mid; }
			else { low = mid + 1; flag = true; }
		}

		if (!flag) 
		{
			if (n - prev > 0) { low = mid + 1; }
			else { ans = mid; high = mid - 1; }
		}
	}

	cout << ans;

	return 0;
}