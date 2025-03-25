#include<iostream>
#include<string>
#include<map>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    int N, M;
    cin >> N >> M;
    map<int, string> name;
    map<string, int> num;

    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        name.insert({i+1, s});
        num.insert({s, i+1});
    }

    for(int i = 0; i < M; i++)
    {
        string s;
        cin >> s;

        if(!atoi(s.c_str()))
        {
            cout << num.at(s) << "\n";
        }
        else if(atoi(s.c_str()))
        {
            int n = atoi(s.c_str());
            cout << name.at(n) << "\n";
        }
    }
    return 0; 
}