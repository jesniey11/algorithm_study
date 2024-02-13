#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int n, ans;
	cin >> n;

	vector<vector<int>> rgb(n, vector<int>(3));

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < 3; j++) { cin >> rgb[i][j];	}
	}

	for (int i = 1; i < n; i++)
	{
		rgb[i][0] += min(rgb[i - 1][1], rgb[i - 1][2]);
		rgb[i][1] += min(rgb[i - 1][0], rgb[i - 1][2]);
		rgb[i][2] += min(rgb[i - 1][0], rgb[i - 1][1]);
	}

	ans = min({ rgb[n - 1][0], rgb[n - 1][1], rgb[n - 1][2] });

	cout << ans;

	return 0;
}