#include<iostream>
#include<string>

using namespace std;

int main()
{
    string S, P;
    int ans = 0;
    cin >> S >> P;

    for(int i = 0; i < P.size();) 
    {
        int maxi = 0;
        for(int a = 0; a < S.size(); a++) 
        {
            int b = 0;
            while(P[i+b] == S[a+b]) b++;
            maxi = max(maxi, b);
        } 

        i += maxi;
        ans++;
    }

    cout << ans;
    return 0;
}