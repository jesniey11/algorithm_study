#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end(), greater<>());

    cout << str;
    return 0;
}