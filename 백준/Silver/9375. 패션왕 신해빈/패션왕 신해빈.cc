#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int tc, n, answer;
string f, kind;

int main() {
	cin >> tc;

	for (int t = 0; t < tc; t++) 
	{
		cin >> n;
		answer = 1;
		map<string, int> apparel;
			
		for (int i = 0; i < n; i++)
		{
			cin >> f >> kind;
			apparel.insert({kind, apparel[kind]++});
		}

		for (auto i = apparel.begin(); i != apparel.end(); i++) 
		{			
			answer *= i->second + 1;
		}

		cout << answer - 1 << endl;
	}

	return 0;
}