#include<iostream>

using namespace std;

bool checkVowel(char c)
{
    switch (c) 
    {
        case 'a': case 'e': case 'i': case 'o': case 'u': return true;
    }

    return false;
}

int main()
{
    while(true)
    {
        string pw;
        cin >> pw;
        if(pw == "end") break;

        bool vow = false, seq3 = false, seq2 = false;

        for(int i = 0; i < pw.size(); i++) 
        {
            // 모음 확인
            if(!vow) vow = checkVowel(pw.at(i));

            // 자음/모음 연속 3개 확인
            if(i+2 < pw.size()) 
            {
                bool a = checkVowel(pw.at(i));
                bool b = checkVowel(pw.at(i+1));
                bool c = checkVowel(pw.at(i+2));

                if ((a == b) && (b == c)) seq3 = true;
                if(seq3) break; // 자음/모음 연속 3개 -> 품질 나쁨 확정
            }

            // 연속 2개 확인
            if(i+1 < pw.size()) 
            {
                if (pw.at(i) == pw.at(i+1) && pw.at(i) != 'e' && pw.at(i) != 'o') seq2 = true;
                if(seq2) break; // 같은 글자 연속 2개 -> 품질 나쁨 확정
            }
        }

        cout << "<" << pw << ">";
        if(vow && !seq3 && !seq2) cout << " is acceptable.\n";
        else cout << " is not acceptable.\n";
    }

    return 0;
}