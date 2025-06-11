#include<iostream>
#include<list>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    
    int T; cin >> T;
    while(T--)
    {
        list<char> pw;
        list<char>::iterator it;
        string str; cin >> str;

        it = pw.begin();

        for(int i = 0; i < str.size(); i++) 
        {
            switch (str[i])
            {
                case '<': 
                    if(it != pw.begin()) it--; break;
                case '>': 
                    if(it != pw.end()) it++; break;
                case '-': 
                    if(it != pw.begin()) it = pw.erase(--it); break;
                default:
                    it = pw.insert(it, str[i]); it++;
            }
        }

        for(auto a : pw) cout << a;
        cout << "\n";
    }

    return 0;
}