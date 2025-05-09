#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N;
    vector<pair<int, int>> v;
    cin >> N;

    for(int i = 0; i < N; i++) 
    {
        int x, y; // 몸무게, 키
        cin >> x >> y;

        v.push_back({x, y});
    }

    for(int i = 0; i < N; i++) 
    {
        int rank = 1;
        for(int j = 0; j < N; j++) 
        {
            if(i == j) continue;
            if(v[i].first < v[j].first && v[i].second < v[j].second) rank++;
        }
        
        cout << rank << " ";
    }

    return 0;
} 