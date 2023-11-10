#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() 
{
	int player, m, l;
	bool flag;
	
	string n;
	cin >> player >> m;
	
	vector<vector<pair<string, int>>> room;

	for (int p = 0; p < player; p++)
	{ 
		cin >> l >> n;
		flag = false;

		for (int i = 0; i < room.size() && !flag; i++)
		{
			// 지금 보는 방이 빈방 -> 새 방 만들기  
			if (room[i].empty()) { break; }

			// 지금 보는 방은 풀방 -> 다음 방 보러가기
			if (room[i].size() >= m) { continue; }

			// 방장과 레벨 차이가 10 이상 -> 다음 방 보러가기
			if (abs(room[i][0].second - l) > 10) { continue; }

			// 방에 입장하고 순회 종료
			room[i].push_back({ n,l });
			flag = true;
		}

		if (!flag) { room.push_back({ {n,l} }); }
	}

	for (int i = 0; i < room.size(); i++) 
	{
		sort(room[i].begin(), room[i].end());

		if (room[i].size() == m) { cout << "Started!" << "\n"; }
		else { cout << "Waiting!" << "\n"; }

		for (int j = 0; j < room[i].size(); j++) 
		{
			cout << room[i][j].second << " " << room[i][j].first << "\n";
		}
	}

	return 0;
} 