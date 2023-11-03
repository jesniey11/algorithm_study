#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name, g;
	float time, tot, tsc;
	float score[9] = { 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0 };
	string grade[9] = { "A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F" };

	tot = 0.f;
	tsc = 0.f;

	for (int i = 0; i < 20; i++) 
	{
		cin >> name >> time >> g;

		if (g == "P") { continue; }
		tot += time;

		for (int j = 0; j < 9; j++)
		{
			if (g == grade[j]) { tsc += time * score[j]; }
		}
	}

	cout << tsc / tot;

	return 0;
}