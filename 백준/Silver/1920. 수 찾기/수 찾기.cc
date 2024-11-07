#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> A;

void fastio()
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int find(int m)
{
    int start = 0;
    int end = N-1;
        
    while(start <= end) 
    {
        int mid = (start+end)/2;
            
        if(A[mid]==m) return 1;
        else if (m < A[mid]) end = mid-1;
        else start = mid+1;
    }

    return 0;
}

int main()
{
    fastio();

    cin >> N;
    A = vector<int>(N);

    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    cin >> M;
    
    for(int i=0; i<M; i++)
    {
        int t;
        cin >> t;

        cout << find(t) << "\n";
    }

    return 0;
} 