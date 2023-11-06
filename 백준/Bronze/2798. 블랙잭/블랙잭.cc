#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, answer;
int* card;

int main() {
	cin >> n >> m;
	card = new int[n];
	answer = 0;

	for (int i = 0; i < n; i++) { cin >> card[i]; }
    
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++) 
		{
			for (int k = j+1; k < n; k++)
			{
				int sum = card[i] + card[j] + card[k];
				if (sum <= m && sum > answer) { answer = sum; }
			}
		}
	}
	cout << answer;
	return 0;
}