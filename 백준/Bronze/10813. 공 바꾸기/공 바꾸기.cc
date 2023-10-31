#include <iostream>
using namespace std;
int main() {
	int n, m, a, b, tmp;
	cin >> n >> m;
	
	int* basket = new int[n];
	for (int i = 0; i < n; i++) {
		basket[i] = i+1;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		int tmp = basket[a - 1];
		basket[a - 1] = basket[b - 1];
		basket[b - 1] = tmp;
	}

	for (int i = 0; i < n; i++) {
		cout << basket[i] << " ";
	}

	return 0;
}