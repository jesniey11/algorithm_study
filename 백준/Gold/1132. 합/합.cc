#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N; 
    long long ans = 0;
    vector<string> str(50);
    vector<long long> alpha(10);
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        string s; cin >> s; str[i] = s;
        long long k = 1;
        for(int j = s.size()-1; j >= 0; j--)
        {            
            int t = s[j] - 'A';
            alpha[t] += k;
            k *= 10;
        }
    }

    bool atoj = true;
    for(int i = 0; i < 10; i++) 
    {
        if(!alpha[i]) atoj = false;
    }

    if(atoj) 
    {
        int zidx = 0;
        long long min = 999999999999;
        for (int i = 0; i < 10; i++) 
        {
            bool usedFirst = false;
            char ch = 'A' + i;

            for (int j = 0; j < N; j++) 
            {
                if (str[j][0] == ch) 
                {
                    usedFirst = true;
                    break;
                }
            }

            if (!usedFirst) 
            {
                if (alpha[i] < min) 
                {
                    min = alpha[i];
                    zidx = i;
                }
            }
        }

        if (zidx != -1) alpha[zidx] = 0;
    }

    sort(alpha.begin(), alpha.end(), greater<>());
    for(int i = 0; i < 10; i++) 
    {
        ans += alpha[i] * (10-1-i);
    }

    cout << ans;
    return 0;
} 