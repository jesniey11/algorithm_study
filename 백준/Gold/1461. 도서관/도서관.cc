#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N, M, ans = 0, maxdist = 0;
    vector<int> pbook, nbook;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        int b; cin >> b;

        if(b > 0) pbook.push_back(b);
        else nbook.push_back(b);

        maxdist = max(maxdist, abs(b));
    }

    sort(pbook.begin(), pbook.end(), greater<>());
    sort(nbook.begin(), nbook.end());

    for(int i = 0; i < pbook.size(); i+=M) ans += pbook[i]*2;
    for(int i = 0; i < nbook.size(); i+=M) ans += -nbook[i]*2;

    cout << ans - maxdist;
    return 0;
}