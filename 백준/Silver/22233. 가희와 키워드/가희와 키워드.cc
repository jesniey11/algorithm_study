#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;

void fastio() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main() 
{	
	fastio();

	int n, m, ans;
	string s, token;
	unordered_set<string> keyword;

	cin >> n >> m;
	ans = n;

	//for (int i = 1; i <= n; i++) { cin >> keyword[i]; }
	//for (int i = 1; i <= m; i++) { cin >> post[i]; }

	for (int i = 0; i < n; i++) { cin >> s; keyword.insert(s); }
	for (int i = 0; i < m; i++) 
	{ 
		cin >> s;
		stringstream ss(s);

		while (getline(ss, token, ',')) 
		{
			if (keyword.count(token) != 0) { keyword.erase(token); ans--; }
		}

		cout << ans << "\n";
	}

	return 0;
}