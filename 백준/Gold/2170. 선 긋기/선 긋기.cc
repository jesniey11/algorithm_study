#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//TODO
//1. 겹쳐지는 선 처리
//2. 끊어진 선 처리

//정렬 -> 0부터

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int ans = 0;
	vector<pair<int,int>> line;

	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		int x, y;
		cin >> x >> y;

		line.push_back(make_pair(x, y));
	}

	//first 기준 정렬
	sort(line.begin(), line.end());
	
	int start = line[0].first;
	int end = line[0].second;

	for (int i = 1; i < N; i++)
	{
		if (line[i].first > end) 
		{
			ans += end - start;
			start = line[i].first;
		}

		end = max(line[i].second, end);
	}

	ans += end - start;
	cout << ans;

	return 0;
}