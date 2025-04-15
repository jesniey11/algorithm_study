#include<iostream>
#include<vector>

using namespace std;

int N, K, P, X, ans;
int number[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011}; // 0 ~ 9

// 디스플레이 반전 횟수
int toggle(int a, int b)
{
    int cnt = 0; 
    int xr = number[a] ^ number[b];
    for (int i = 0; i < 7; i++)
    {
        if (xr & (1 << i)) cnt++;
    }

    return cnt;
}

// 바뀐 층수 A, 원래 층수 X 분할
vector<int> split(int x)
{
    vector<int> v;

    while (x > 0)
    {
        v.push_back(x % 10);
        x /= 10;
    }

    return v;
}

int main()
{
    cin >> N >> K >> P >> X;
    
    for(int a = 1; a <= N; a++)
    {
        int cnt = 0;
        if(a == X) continue;

        vector<int> va = split(a), vx = split(X);
        int s = max(va.size(), vx.size());

        for(int i = 0; i < s; i++)
        {
            // A와 X중 자리수 짧은 쪽은 false => 0
            int fA = (i < va.size()) ? va[i] : 0;
            int fX = (i < vx.size()) ? vx[i] : 0;

            cnt += toggle(fA, fX);
        }

        if(cnt <= P) ans++;        
    }

    cout << ans;
    return 0;
}