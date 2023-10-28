#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n += 1;

	for (int i = 1; i < n; i++) {
		for (int k = i; k < n-1; k++) { cout << " "; }
		for (int j = 0; j < i; j++) { cout << "*"; }
		cout << "\n";
	}
}