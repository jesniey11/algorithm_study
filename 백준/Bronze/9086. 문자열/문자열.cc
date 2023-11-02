#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	string str;
	char start, end;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> str;
		
		// #1번
		//start = str[0];
		//end = str[str.length()];

		// #2번
		//start = str.at(0);
		//end = str.at(str.length());

		// #3번
		start = str.front();
		end = str.back();

		cout << start << end << "\n";
	}

	return 0;
}