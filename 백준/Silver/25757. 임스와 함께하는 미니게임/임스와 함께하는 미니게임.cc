#include<iostream>
#include<set>

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

    int N;
    char game;
    set<string> user;

    cin >> N >> game;
    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        user.insert(s);
    }

    int player; // 임스를 제외한 플레이어 수
    switch (game)
    {
        case 'Y': player = 1; break;
        case 'F': player = 2; break;
        case 'O': player = 3; break;
    }

    cout << user.size() / player;
    return 0;
}