#include <iostream>
#include <stack>

using namespace std;

int main() 
{
	stack<char> sin, sout;
	string str;
	int m;

	cin >> str >> m;

	for (int i = 0; i < str.length(); i++) { sin.push(str.at(i)); }
	for (int i = 0; i < m; i++) 
	{
		char c;
		cin >> c;

		if (c == 'L' && !sin.empty()) 
		{ 
			sout.push(sin.top()); 
			sin.pop(); 
		}

		if (c == 'D' && !sout.empty()) 
		{ 
			sin.push(sout.top()); 
			sout.pop(); 
		}

		if (c == 'B' && !sin.empty()) { sin.pop(); }

		if (c == 'P') 
		{ 
			cin >> c; 
			sin.push(c); 
		}
	}

	while (!sin.empty()) 
	{
		sout.push(sin.top());
		sin.pop();
	}

	m = sout.size();

	for (int i = 0; i < m; i++) 
	{
		cout << sout.top();
		sout.pop();
	}

	return 0;
}