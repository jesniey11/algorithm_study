#include <iostream>
#include <algorithm>

using namespace std;

void fastio() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() 
{
	fastio();
	int n, m, sum, ans;
	
	cin >> n;
	ans = 0;
	sum = 0;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i]; 
		sum += arr[i];
	}

	cin >> m;
	sort(arr, arr+n);
	
	if (sum <= m) { cout << arr[n - 1]; return 0; }

	int low, high, mid;
	
	low = 0;
	high = arr[n - 1];

	while (low <= high)
	{
		// mid = 상한액
		mid = (low + high) / 2;
		sum = 0;

		for (int i = 0; i < n; i++) { sum += min(arr[i], mid); }
		if (sum <= m) { ans = mid; low = mid + 1; }
		else { high = mid - 1; }
	}

	cout << ans;

	return 0;
}