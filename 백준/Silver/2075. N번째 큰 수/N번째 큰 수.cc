#include <iostream>
#include <queue>

using namespace std;

void fastio() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main() 
{
	fastio();

	int n, a;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> q;
	
	for (int i = 0; i < n*n; i++) 
	{
		cin >> a;
		q.push(a);
		if (q.size() > n) { q.pop(); }
	}

	cout << q.top();

	return 0;
}