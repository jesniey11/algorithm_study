#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void fastio() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	fastio();

	int n, m;
	cin >> n >> m;

	map<int, string> title;
	vector<int> user(m);

	string str;
	int pow;

	for (int i = 0; i < n; i++) 
	{
		cin >> str >> pow;

		if (!title[pow].empty()) { continue; }
		title[pow] = str;
	}

	for (int i = 0; i < m; i++) 
	{ 
		cin >> pow;
		cout << (title.lower_bound(pow))->second << "\n";
	}
    
	return 0;
}