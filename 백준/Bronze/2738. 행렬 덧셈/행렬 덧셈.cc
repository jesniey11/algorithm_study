#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> pa(n, vector<int>(m));
	vector<vector<int>> pb(n, vector<int>(m));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { cin >> pa[i][j]; }
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { cin >> pb[i][j]; }
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { cout << pa[i][j] + pb[i][j] << " ";  }
		cout << "\n";
	}

	return 0;
}