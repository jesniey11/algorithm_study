#include<iostream>
#include<map>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    map<string, string> memo;

    for(int i = 0; i < N; i++) 
    {
        string link, pw;
        cin >> link >> pw;
        memo.insert({link, pw});
    }

    for(int i = 0; i < M; i++) 
    {
        string link;
        cin >> link;
        cout << memo.at(link) << "\n";
    }
    
    return 0;
}
