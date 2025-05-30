#include<iostream>
#include<deque>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int size = S.size();
    deque<char> dq;

    for(int i = 0; i < size; i++)
    {
        char c = S[i];

        if(dq.empty()) dq.push_back(c);
        else
        {
            if(c <= dq.front()) dq.push_front(c);
            else dq.push_back(c);
        }
    }

    for(int i = 0; i < size; i++) 
    {
        cout << dq.front();
        dq.pop_front();
    }

    return 0;
}