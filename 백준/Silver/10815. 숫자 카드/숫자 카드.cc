#include <iostream>
#include <map>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
	int n, m, input;
	map<int, int> card;

	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		cin >> input;
		card.insert({ input, 1 });
	}

	cin >> m;

	for (int i = 0; i < m; i++) 
	{
		cin >> input;
		if (card[input] == 1) { cout << 1; }
		else { cout << 0; }
		cout << " ";
	}

	return 0;
}