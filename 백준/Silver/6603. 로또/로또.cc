#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
	int k;
	while (true) 
	{
		cin >> k;
		if (k == 0) { break; }

		vector<int> s(k);
		vector<int> index(k);

		for (int i = 0; i < k; i++)	{ cin >> s[i]; }
		for (int i = 0; i < 6; i++)	{ index[i] = 1; }

		do {
			for (int i = 0; i < k; i++)
			{
				if (index[i] == 1) { cout << s[i] << " "; }
			}
			cout << endl;
		} while (prev_permutation(index.begin(), index.end()));

		cout << endl;
	}
	return 0;
}