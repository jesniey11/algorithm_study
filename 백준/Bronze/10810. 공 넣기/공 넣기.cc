#include <iostream>
using namespace std;
int main() {
	int n, m, i, j, k;
	cin >> n >> m;
	int* basket = new int[n];
	
	for (int a = 0; a < n; a++) {
		basket[a] = 0;
	}

	for (int a = 0; a < m; a++) {
		cin >> i >> j >> k;
		
		for (int b = i - 1; b < j; b++) {
			basket[b] = k;
		}
	}

	for (int a = 0; a < n; a++) {
		cout << basket[a] << " ";
	}

	return 0;
}