#include<iostream>
#include<algorithm>
using namespace std;
int main() 
{
	int a, b, c;
	cin >> a >> b >> c;

	int num[3] = {a, b, c};

	sort(num, num+3);
	for (int i = 0; i < 3; i++) { cout << num[i] << " "; }

	return 0;
}