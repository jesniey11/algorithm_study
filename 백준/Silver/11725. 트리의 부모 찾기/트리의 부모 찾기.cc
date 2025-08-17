#include<iostream>
#include<vector>

#define MAX 100001

using namespace std;

int N, a, b;
vector<int> tree[MAX];
int parent[MAX]; 
bool visit[MAX];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void DFS(int x)
{
    visit[x] = true;

    for(int i = 0; i < tree[x].size(); i++) 
    {
        int n = tree[x][i];
        if(!visit[n])
        {
            parent[n] = x; DFS(n);
        }
    }
}

int main()
{
    fastio();

    cin >> N;
    for(int i = 0; i < N-1; i++) 
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    DFS(1);

    for(int i = 2; i <= N; i++) cout << parent[i] << '\n';
    return 0;
}