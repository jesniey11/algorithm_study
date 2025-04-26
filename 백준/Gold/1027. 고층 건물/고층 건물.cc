#include<iostream>

using namespace std;

int main()
{
    int N, ans = 0;
    long long bd[51];
    cin >> N;

    for(int i = 1; i <= N; i++) cin >> bd[i];

    for(int i = 1; i <= N; i++) 
    {
        // i = 탐색 기준점
        int cnt = 0; // i에서 보이는 빌딩 수

        for(int l = 1; l < i; l++) 
        {
            // l = i의 왼쪽에 있는 빌딩
            double a = (double)(bd[i]-bd[l])/(i-l);
            double b = bd[l]-(a*l);
            bool flag = true;

            for(int j = l+1; j < i; j++) 
            {
                if((a*j)+b <= bd[j]) 
                {
                    flag = false;
                    break;
                }
            }

            if(flag) cnt++;
        }

        for(int r = i+1; r <= N; r++) 
        {
            // r = i의 오른쪽에 있는 빌딩
            double a = (double)(bd[r]-bd[i])/(r-i);
            double b = bd[r]-(a*r);
            bool flag = true;

            for(int j = i+1; j < r; j++) 
            {
                if((double)(a*j)+b <= bd[j]) 
                {
                    flag = false;
                    break;
                }
            }

            if(flag) cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}