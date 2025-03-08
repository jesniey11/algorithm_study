#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

char chalpha(char c) {
    if (c >= 'a' && c <= 'z') return c - ('a' - 'A');
    else return c + ('a' - 'A');
}

int main() {
    set<char> set;
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        bool flag = false;
        int i1, i2;
        string s;
        getline(cin, s);

        stringstream ss(s);
        vector<string> words;
        string word;
        // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 결과 배열에 저장
        while (getline(ss, word, ' ')) {
            words.push_back(word);
        }

        //일단 단어별로 앞글자 확인
        for (int j = 0; j < words.size(); j++) {
            if (set.find(words[j][0]) == set.end()) {
                set.insert(words[j][0]);
                set.insert(chalpha(words[j][0]));
                i1 = j;
                i2 = 0;
                flag = true;
                break;
            }
        }
        //한글자한글자 확인
        if (!flag) {
            for (int j = 0; j < words.size(); j++) {
                if (flag) break;
                for (int k = 1; k < words[j].length(); k++) {
                    if (set.find(words[j][k]) == set.end()) {
                        set.insert(words[j][k]);
                        set.insert(chalpha(words[j][k]));
                        i1 = j;
                        i2 = k;
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (!flag) {
            for (int j = 0; j < words.size(); j++) {
                cout << words[j] << " ";
            }
            cout << '\n';
        } else {
            for (int j = 0; j < words.size(); j++) {
                if (i1 == j) {
                    for (int k = 0; k < words[j].length(); k++) {
                        if (k == i2) {
                            cout << "[" << words[j][k] << "]";
                        } else cout << words[j][k];
                    }
                    cout << " ";
                } else cout << words[j] << " ";
            }
            cout << '\n';
        }
    }
}