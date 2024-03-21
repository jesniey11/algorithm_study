#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int n, a;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) 
	{ 
		cin >> a;
		
		for (int j = 0; j < n; j++) 
		{
			if (v[j] == 0) 
			{
				if (a == 0) { v[j] = i + 1; break; }
				a--;
			}
		}
	}

	for (int i = 0; i < n; i++) { cout << v[i] << " "; }

	return 0;
}