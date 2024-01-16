#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, input;
	cin >> n;

	vector<int> card(n);
	
	for (int i = 0; i < n; i++) { cin >> card[i]; }

	sort(card.begin(), card.end());

	cin >> m;
	int low, high, mid;

	low = 0;
	high = m - 1;

	for (int i = 0; i < m; i++) 
	{
		cin >> input;
		if (binary_search(card.begin(), card.end(), input)) { cout << "1 "; }
		else { cout << "0 "; }
	}

	return 0;
}
