#include <iostream>
using namespace std;
int main() 
{
	int n, num, answer;
	cin >> n;

	num = 1;
	answer = 1;

	while (num < n)
	{
		num += answer * 6;
		answer++;
	}

	cout << answer;
}