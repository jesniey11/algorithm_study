#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> order;

bool compare(const pair<int, int> a, const pair<int, int> b)
{
	if (a.second == b.second) { return order[a.first] < order[b.first]; }
	else { return a.second > b.second; }
}

int main() 
{
	int n, c, input;
	cin >> n >> c;

	map<int, int> number;

	for (int i = 0; i < n; i++) 
	{
		cin >> input;
		number[input]++;

		if (order[input] == 0) { order[input] = i + 1; }
	}

	vector<pair<int, int>> v(number.begin(), number.end());
	sort(v.begin(), v.end(), compare);

	for (auto a : v) 
	{
		for (int i = 0; i < a.second; i++) { cout << a.first << " "; }
	}

	return 0;
}