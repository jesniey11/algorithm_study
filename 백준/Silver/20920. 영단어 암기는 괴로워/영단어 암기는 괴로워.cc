#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void fastio() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
bool compare(const pair<string, int> &a, const pair<string, int> &b)
{
	// 빈도
	if (a.second == b.second)
	{
		// 단어길이
		if (a.first.length() == b.first.length()) 
		{ 
			// 알파벳순서
			return (a.first < b.first); 
		}
		else { return (a.first.length() > b.first.length()); }
	} else { return (a.second > b.second); }
}

int main() 
{
	fastio();

	int n, m;
	cin >> n >> m;

	map<string, int> word;
	
	string str;
	for (int i = 0; i < n; i++) 
	{
		cin >> str;		
		if (str.length() < m) { continue; }
		word[str]++;
	}

	vector<pair<string, int>> voca(word.begin(), word.end());
	sort(voca.begin(), voca.end(), compare);

	for (auto au : voca) { cout << au.first << "\n"; }
	return 0;
}