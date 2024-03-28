#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int ib[1001][1001], ob[1001][1001];
bool visit[1001][1001];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void fastio() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void bfs(int a, int b) 
{
	queue<pair<int,int>> q;
	q.push(make_pair(a, b));
	visit[a][b] = true;
	
	while (!q.empty()) 
	{
		int nx, ny;

		pair<int, int> nq = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			nx = nq.first + dx[i];
			ny = nq.second + dy[i];

			if (nx < 0 || n <= nx || ny < 0 || m <= ny || visit[nx][ny] || ib[nx][ny] == 0) { continue; }
			else 
			{
				ob[nx][ny] = ob[nq.first][nq.second] + 1;
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() 
{
	fastio();

	int x = 0, y = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{ 
			cin >> ib[i][j];
			if (ib[i][j] == 2) { x = i; y = j; }
			else { ob[i][j] = ib[i][j] * -1; }
		}
	}

	bfs(x, y);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) { cout << ob[i][j] << " "; }
		cout << "\n";
	}

	return 0;
}