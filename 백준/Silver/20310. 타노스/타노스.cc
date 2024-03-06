#include <iostream>
//#include <string>

using namespace std;

int main() 
{
	int one = 0, zero;
	string s, ans;
	cin >> s;

	for (int i = 0; i < s.length(); i++) 
	{
		if (s.at(i) == '1') { one++; }
	}

	zero = (s.length() - one) / 2;
	one /= 2;

	int a = s.length() - 1;
	while (zero > 0) 
	{
		if (s.at(a) == '0') 
		{
			s.at(a) = '-';
			zero--;
		}
		a--;
	}

	int b = 0;
	while (one > 0)
	{
		if (s.at(b) == '1')
		{
			s.at(b) = '-';
			one--;
		}
		b++;
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) == '-') { continue; }
		ans.push_back(s.at(i));
	}

	cout << ans;

	return 0;
}