#include <iostream>

using namespace std;

int main() 
{
	int n, ans = 0, left = 0, right = 0;
	int mh = 0, mi = 0;
	int pillar[1001] = {};
	cin >> n;
	
	for (int i = 0; i < n; i++) 
	{
		int l, h;
		cin >> l >> h;

		pillar[l] = h;

		if (mh < h) { mi = l; mh = max(mh, h); }
	}

	for (int i = 1; i < mi; i++)
	{
		left = max(left, pillar[i]);
		ans += left;
	}

	for (int i = 1000; i > mi; i--)
	{
		right = max(right, pillar[i]);
		ans += right;
	}

	ans += mh;
	cout << ans;

	return 0;
}