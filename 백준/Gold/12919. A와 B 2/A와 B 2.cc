#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string S, T;
bool flag = false;

void TtoS(string str)
{
    int len = str.size();

    if(len == S.size())
    {
        if(str == S) flag = true;
        return;
    }

    string strA = str;
    if(strA.back() == 'A')
    {
        strA.erase(len-1);
        TtoS(strA);
    }

    string strB = str;
    reverse(strB.begin(), strB.end());
    if(strB.back() == 'B')
    {
        strB.erase(len-1);
        TtoS(strB);
    }

    return;
}

int main()
{
    cin >> S >> T;
    TtoS(T);

    cout << flag;
    return 0;
}