#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, answer;
bool* visit;
int* card;

void selectCard(int cnt, int now) {

	if (now == 3) {
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (visit[i]) { sum += card[i]; }
			if (sum > m) { sum = 0; break; }
		}

		answer = max(answer, sum);
        return;
	}

	for (int i = cnt; i < n; i++) 
	{
		visit[i] = true;
		selectCard(i + 1, now + 1);
		visit[i] = false;
	}
}

int main() {
	cin >> n >> m;

	card = new int[n];
	visit = new bool[n];
	
	answer = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> card[i];
	}

	selectCard(0, 0);
	cout << answer;

	return 0;
}