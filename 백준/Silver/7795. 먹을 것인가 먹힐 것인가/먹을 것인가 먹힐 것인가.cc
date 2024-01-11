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
		int n, m, ans;
		cin >> n >> m;
		ans = 0;

		vector<int> a(n);
		vector<int> b(m);

		for (int i = 0; i < n; i++) { cin >> a[i]; }
		for (int i = 0; i < m; i++) { cin >> b[i]; }

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int low, high, mid, sum;

		for (int i = 0; i < n; i++) 
		{
			low = 0;
			high = m - 1;
			sum = 0;

			while (low <= high)
			{
				mid = (low + high) / 2;

				if (b[mid] < a[i]) { low = mid + 1; sum = mid+1; }
				else { high = mid - 1; }
			}
			ans += sum;
		}

		cout << ans << endl;
	}

	return 0;
}