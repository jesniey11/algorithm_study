#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
vector<int> card;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    
    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        int x; cin >> x;
        card.push_back(x);
    }

    sort(card.begin(), card.end());

    cin >> M;
    for(int i = 0; i < M; i++) 
    {
        int num; cin >> num;
        cout << upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num) << " ";
    }

    return 0;
}