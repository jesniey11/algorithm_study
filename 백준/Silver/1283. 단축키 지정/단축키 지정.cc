#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    
    fastio();
    
    int n;
    bool alpha[26] = {false};
    
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) 
    {
        //한 줄씩 입력 -> 출력 -> 다음 줄 입력 -> ...
        //words = {Save, As, Other, Folder} 같은 식으로 나올 예정
        vector<string> words;
        
        string line;
        getline(cin, line);

        string word;
        stringstream ss(line);
        
        //spilt line to words
        while (getline(ss, word, ' ')) 
        {
            words.push_back(word);
        }

        bool flag = false;
        int idx_a = 0, idx_b = 0;

        //단어별 첫글자
        for (int j = 0; j < words.size(); j++) 
        {
            int alpha_index = (words[j][0] >= 'a') ? words[j][0] - 'a' : words[j][0] - 'A';
            if(!alpha[alpha_index])
            {
                alpha[alpha_index] = true;
                flag = true;
                idx_a = j; 
                idx_b = 0;
                break;
            }
        }
        
        //전체 글자 확인
        if(!flag) 
        {
            for (int j = 0; j < words.size(); j++) 
            {
                if(flag) break;

                for (int k = 1; k < words[j].length(); k++) 
                {
                    int alpha_index = (words[j][k] >= 'a') ? words[j][k] - 'a' : words[j][k] - 'A';
                    if(!alpha[alpha_index])
                    {   
                        alpha[alpha_index] = true;
                        flag = true;
                        idx_a = j; 
                        idx_b = k;
                        break;
                    }
                }
            }
        }
        
        //어느 단축키도 설정하지 못함
        if(!flag) 
        {
            for (int j = 0; j < words.size(); j++) 
            {
                cout << words[j] << " ";
            }
            cout << "\n";
        } 
        else 
        {
            for (int j = 0; j < words.size(); j++) 
            {
                if(idx_a == j) 
                {
                    for (int k = 0; k < words[j].length(); k++) 
                    {
                        if(idx_b == k) cout << '[' << words[j][k] << ']';
                        else cout << words[j][k];     
                    }
                    cout << " ";
                }
                else cout << words[j] << " ";
            }
            cout << "\n";
        }
    }
}