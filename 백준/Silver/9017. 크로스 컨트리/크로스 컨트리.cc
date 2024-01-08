#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int tc, n, m, ans;
	cin >> tc;

	for (int t = 0; t < tc; t++)
	{
		ans = 0;
		vector<vector<int>> team(201, vector<int>(3));
		vector<int> input;
		vector<int> teammate(201);

		cin >> n;
		for (int i = 1; i < n + 1; i++)
		{
			cin >> m;
			input.push_back(m);
			teammate[m]++;
		}

		for (int i = 1; i < teammate.size(); i++)
		{
			if (teammate[i] < 6)
			{
				input.erase(remove(input.begin(), input.end(), i), input.end());
			}
		}

		for (int i = 0; i < input.size(); i++) 
		{
			team[input[i]][0]++;

			if (team[input[i]][0] <= 4) { team[input[i]][1] += (i + 1);	}
			if (team[input[i]][0] == 5) { team[input[i]][2] = i + 1; }
		}

		for (int i = 1; i < team.size(); i++) 
		{
			if (team[i][0] == 0) { continue; }
			if (ans == 0) { ans = i; continue; }

			if (team[ans][1] > team[i][1]) { ans = i; }
			if (team[ans][1] == team[i][1]) {
				if (team[ans][2] > team[i][2]) { ans = i; }
			}
		}

		cout << ans << endl;
	}

	return 0;
}