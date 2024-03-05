#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct TeamData
{
	int id, score, submit, last;
	bool operator < (TeamData td) 
	{
		if (score == td.score) 
		{
			if (submit == td.submit) { return last < td.last; }
			return submit < td.submit;
		}
		return score > td.score;
	}
};

int main() 
{
	int testcase;
	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++)
	{
		int n, k, t, m;
		cin >> n >> k >> t >> m;

		//팀 번호 0번, 문제 번호 0번은 사용하지 않음
		vector<TeamData> team(n+1);
		vector<vector<int>> input(n+1, vector<int>(k+1));

		for (int a = 0; a < m; a++) 
		{
			int i, j, s;
			cin >> i >> j >> s;
			
			if (input[i][j] < s) { input[i][j] = s; }
			team[i].submit++;
			team[i].last = a;
		}

		for (int a = 1; a <= n; a++) 
		{
			team[a].id = a;
			for (int b = 1; b <= k; b++) { team[a].score += input[a][b]; }
		}

		sort(team.begin()+1, team.end());

		for (int a = 1; a <= n; a++) 
		{
			if (team[a].id == t) { cout << a << endl; }
		}
	}

	return 0;
}