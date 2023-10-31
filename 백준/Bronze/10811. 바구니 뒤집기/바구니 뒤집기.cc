#include <iostream>
using namespace std;
int main() {
	int n, m, a, b, tmp;
	cin >> n >> m;

	int* basket = new int[n];
	for (int i = 0; i < n; i++) {
		basket[i] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		a -= 1;
		b -= 1;

		for (a; a < b; a++) {
			tmp = basket[a];

			basket[a] = basket[b];
			basket[b] = tmp;

			b--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << basket[i] << " ";
	}

	return 0;
}