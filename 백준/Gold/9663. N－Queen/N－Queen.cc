#include <iostream>
using namespace std;

int n, ans;
int board[15];

bool checkmate(int idx)
{
	for (int i = 0; i < idx; i++)
	{
		if (board[idx] == board[i]
			|| abs(board[idx] - board[i]) == abs(idx - i)) {
			return false;
		}
	}
	return true;
}

void queen(int idx) 
{
	if (idx == n) { ans++; return; }

	for (int i = 0; i < n; i++) 
	{
		board[idx] = i;
		if (checkmate(idx)) { queen(idx + 1); }
	}
}

int main()
{
	cin >> n;
	queen(0);
	cout << ans;
}