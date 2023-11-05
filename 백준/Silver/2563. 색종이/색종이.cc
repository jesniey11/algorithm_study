#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, y, x;
	cin >> n;

	int cnt = 0;

	vector<vector<int>> field(100, vector<int>(100));

	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		for (int a = y; a < y+10; a++) {
			for (int b = x; b < x+10; b++) { field[a][b] = 1; }
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (field[i][j] == 1) { cnt++; }
		}
	}

	cout << cnt;

	return 0;
}