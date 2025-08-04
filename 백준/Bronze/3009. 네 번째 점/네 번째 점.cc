#include<iostream>

using namespace std;

pair<int, int> p[3];
int x, y;

int main()
{
    for(int i = 0; i < 3; i++) 
    {
        cin >> x >> y;
        p[i] = {x, y};
    }

    if(p[0].first == p[1].first) x = p[2].first;
    if(p[0].first == p[2].first) x = p[1].first;
    if(p[1].first == p[2].first) x = p[0].first;

    if(p[0].second == p[1].second) y = p[2].second;
    if(p[0].second == p[2].second) y = p[1].second;
    if(p[1].second == p[2].second) y = p[0].second;

    cout << x << ' ' << y;
    return 0;
}