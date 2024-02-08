#include <iostream>

using namespace std;

int main() 
{
	int n;
	int stair[301], score[301];

	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> stair[i]; }

	score[1] = stair[1]; 
	score[2] = stair[1] + stair[2];
	score[3] = max(stair[1], stair[2]) + stair[3];

	for (int i = 4; i <= n; i++) 
	{
		score[i] = max(score[i-2], score[i-3] + stair[i-1]) + stair[i];
	}
	cout << score[n];

	return 0;
}