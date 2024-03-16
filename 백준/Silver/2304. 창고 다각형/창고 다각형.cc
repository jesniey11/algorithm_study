#include <iostream>
#include <algorithm>
using namespace std;
int N;
int max_pos, max_h; // 최대 높이의 위치와 높이
int arr[1001];
int res = 0;
int main(void)
{
	int L, H;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> L >> H;
		arr[L] = H;
		if (max_h < H)
		{
			max_pos = L;
			max_h = H;
		}
	}

	int Lh=0; // 왼쪽 영역의 최고 높이
	for (int i = 1; i <max_pos; i++)
	{
		Lh = max(Lh, arr[i]);
		res += Lh;
	}

	int Rh=0; // 오른쪽 영역의 최고 높이
	for (int i = 1000; i > max_pos; i--)
	{
		Rh = max(Rh, arr[i]);
		res += Rh;
	}

	cout << res + max_h;
}