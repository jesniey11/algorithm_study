#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() 
{
	int n, m, sum;
	string a, b;
	cin >> n >> m;
	vector<vector<string>> dp(101, vector<string>(101));

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 0; j <= i; j++) 
		{
			if (j == 0 || j == i) { dp[i][j] = '1'; }
			else {
				sum = 0;
				a = dp[i - 1][j - 1];
				b = dp[i - 1][j];

				while (!a.empty() || !b.empty() || sum != 0) 
				{
					if (!a.empty()) {
						sum += a.back() - '0';
						a.pop_back();
					}

					if (!b.empty()) {
						sum += b.back() - '0';
						b.pop_back();
					}

					dp[i][j].push_back((sum % 10) + '0');
					sum /= 10;
				}

				reverse(dp[i][j].begin(), dp[i][j].end());
			}
		}
	}
    
	cout << dp[n][m];
	return 0;
}