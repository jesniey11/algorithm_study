#include <iostream>
using namespace std;
int main() 
{
	long s, n, i;
	n = 0; i = 1;
	cin >> s;

	while (s >= i) {
		s -= i;
		i++;
		n++;
	}

	cout << n;
}