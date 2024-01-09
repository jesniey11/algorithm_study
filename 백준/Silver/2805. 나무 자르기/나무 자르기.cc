#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	long long n, m, ans;	
	cin >> n >> m;
	vector<int> tree(n);

	long long low, high, mid, sum;
	
	for (int i = 0; i < n; i++) { cin >> tree[i]; }
	sort(tree.begin(), tree.end());

	ans = 0;
	low = 0;
	high = tree[n-1];

	while (low <= high) 
	{
		mid = (low + high) / 2;
		sum = 0;

		for (int i = 0; i < n; i++) 
		{
			if (tree[i] - mid > 0) { sum += tree[i] - mid; }
		}

		if (sum >= m) 
		{
			low = mid + 1;
			if (mid > ans) { ans = mid; }
		}
		else { high = mid - 1; }
	}

	cout << ans;

	return 0;
}