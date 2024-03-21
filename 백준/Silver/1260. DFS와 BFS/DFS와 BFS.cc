#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m, v;
int arr[1001][1001] = {};
bool visit[1001] = {};

void dfs(int a) 
{
	cout << a << " ";
	visit[a] = true;

	for (int i = 1; i <= n; i++) 
	{
		if (arr[a][i] == 1 && !visit[i]) { dfs(i); }
	}

	return;
}
void bfs() 
{
	queue<int> q;

	q.push(v);
	visit[v] = true;

	while (!q.empty()) 
	{
		int a = q.front();
		q.pop();
		cout << a << " ";

		for (int i = 1; i <= n; i++)
		{
			if (arr[a][i] == 1 && !visit[i]) 
			{
				q.push(i);
				visit[i] = true;
			}
		}
	}

	return;
}

int main() 
{
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) 
	{
		int a, b;
		cin >> a >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(v);

	cout << endl;

	memset(visit, false, 1001);
	bfs();

	return 0;
}