#include <iostream>
using namespace std;
int main() 
{
	long s, n, i;
	n = 0; i = 1;
	cin >> s;

	while (true) 
	{
		if ((s - i) < 0) { break; }
		if ((s - i) == 0) { n++; break; }

		n++;
		s -= i;
		i++;
	}

	cout << n;
}