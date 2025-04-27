#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N, M = -1;
    string ans1, ans2;
    vector<string> in, copy;
    
    cin >> N;
    for(int i = 0; i < N; i++) 
    {
        string s; 
        cin >> s;
        in.push_back(s);
    }

    for(int i = 0; i < N; i++) 
    {
        for(int j = i+1; j < N; j++) 
        {
            int cnt = 0;
            int size = min(in[i].size(), in[j].size());

            while(cnt < size && in[i][cnt] == in[j][cnt]) cnt++;

            if(M < cnt) 
            {
                ans1 = in[i];
                ans2 = in[j];
                M = cnt;
            }
        }
    }

    cout << ans1 << "\n" << ans2 << "\n";
    return 0;
}