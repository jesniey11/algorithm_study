#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
int dir[3] = { -1, 0, 1 };
vector<vector<int>> space(7, vector<int>(7));

int launch(int r, int c, int prev) 
{
	if (r == n) { return 0; }
	
	int cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		if (prev == i) { continue; }

		int nc = c + dir[i];
		if (nc < 0 || m <= nc) { continue; }
		
		if (cnt == 0) {	cnt = launch(r + 1, nc, i) + space[r][c]; }
		else { cnt = min(cnt, launch(r + 1, nc, i) + space[r][c]); }
	}

	return cnt;
}

int main() 
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) { cin >> space[i][j]; }
	}

	for (int i = 0; i < m; i++) 
	{
		if (ans == 0) { ans = launch(0, i, -1); }
		else { ans = min(ans, launch(0, i, -1)); }
	}

	cout << ans;

	return 0;
}