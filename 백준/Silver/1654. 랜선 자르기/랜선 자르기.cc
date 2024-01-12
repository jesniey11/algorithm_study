#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int k, n, ans;
	ans = 0;

	cin >> k >> n;

	vector<int> lan(k);

	for (int i = 0; i < k; i++) { cin >> lan[i]; }
	sort(lan.begin(), lan.end());

	long long low, high, mid, sum;

	low = 1;
	high = lan[k - 1];

	while (low <= high) 
	{
		mid = (low + high) / 2;
		sum = 0;

		for (int i = 0; i < k; i++)
		{
			sum += lan[i] / mid;
		}

		if (sum < n) { high = mid - 1; }
		else 
		{
			low = mid + 1; 
			if (ans < mid) { ans = mid; }
		}
	}

	cout << ans;
	return 0;
}