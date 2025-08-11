#include<iostream>

#define MAX 1000001

using namespace std;

int N, M, a = 0, b = 0;
int A[MAX], B[MAX], C[MAX*2];

void fastio()
{
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int main()
{
    fastio();
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    for(int i = 0; i < N+M; i++) 
    {
        if (a == N) 
        { 
            C[i] = B[b++]; continue; 
        }
        if (b == M) 
        { 
            C[i] = A[a++]; continue; 
        }

        C[i] = (A[a] <= B[b]) ? A[a++] : B[b++];
    }

    for(int i = 0; i < N+M; i++)
    {
        cout << C[i] << ' ';
    }

    return 0;
}