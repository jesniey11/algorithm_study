#include<iostream>
#include<string>

using namespace std;
int main()
{
    int ans = 0;
    string document, word;
    getline(cin, document);
    getline(cin, word);

    for(int i = 0; i < document.size(); i++) 
    {
        if(document[i] == word[0])
        {
            bool flag = true;
            for(int j = 0; j < word.size(); j++) 
            {
                if(!flag) break;
                
                if(document[i+j] == word[j]) continue;
                else flag = false;
            }
            if(flag) 
            {
                i += word.size()-1;
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
} 