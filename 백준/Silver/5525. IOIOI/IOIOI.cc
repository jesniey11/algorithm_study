#include<iostream>

using namespace std;

int main()
{
    int N, M;
    string S;
    int ans = 0;
    string ioi = "I";

    cin >> N >> M >> S;
    for(int i = 0 ; i < N; i++)
    {
        ioi.append("OI");
    }

    for(int i = 0; i < M-ioi.size()+1; i++)
    {        
        if(S.at(i) != 'I') continue;
        bool flag = false;

        for(int j = 1; j < ioi.size(); j++)
        {
            if(S.at(i+j) != ioi.at(j)) 
            {   
                flag = true;
                break;
            }
        }
        if(!flag) ans++;
    }

    cout << ans;
}