#include <iostream>
#include <string>
using namespace std;
int main() 
{
	int len, ans;
	string str;
	cin >> str;

	len = str.length();
	ans = 1;

	if (len != 1)
	{
		for (int i = 0; i < len / 2; i++)
		{
			if (str[i] == str[len - (1 + i)]) { ans = 1; }
			else 
			{
				ans = 0;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}