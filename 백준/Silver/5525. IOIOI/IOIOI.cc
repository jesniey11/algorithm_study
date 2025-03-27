#include<iostream>

using namespace std;

int main()
{
    int N, M;
    string S;

    cin >> N >> M >> S;
    int ans = 0;

    for(int i = 0; i < M; i++)
    {   
        int ioi = 0;     
        if(S.at(i) != 'I') continue;
        while(S[i+2] == 'I' && S[i+1] == 'O')
        {
            ioi++;

            if(ioi == N) 
            {
                ans++;
                ioi--;
            }
            
            i+=2;
        }    
    }

    cout << ans;
}