#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string input;
	cin >> input;

	int idx = 0;
	int n = 0;
	bool flag = false;

	while (idx++ < 100000) 
	{
		string num = to_string(idx);
		for (int i = 0; i < num.length(); i++) 
		{
			if (input[n] == num[i]) { n++; }
			if (n == input.length()) { flag = true; break; }
		}

		if (flag) { break; }
	}

	cout << idx;
	return 0;
}