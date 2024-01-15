#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() 
{
	int n, x;
	string s;

	cin >> n;

	map<string, int> card;
	vector<string> fruit(n);

	for (int i = 0; i < n; i++) 
	{
		cin >> s >> x;

		fruit[i] = s;
		card[s] += x;
	}

	for (int i = 0; i < n; i++)
	{
		s = fruit[i];
		if (card[s] == 5) { cout << "YES"; return 0; }
	}
	
	cout << "NO";
	return 0;
}