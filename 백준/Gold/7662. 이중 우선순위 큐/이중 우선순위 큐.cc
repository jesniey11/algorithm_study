#include<iostream>
#include<queue>
#include<map>

using namespace std;

int T, k;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;
map<int, int> m;       

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void reset()
{
    while(!maxq.empty()) maxq.pop();
    while(!minq.empty()) minq.pop();
    m.clear();
}

// command: I
void insert(int i)
{
    maxq.push(i);
    minq.push(i);
    m[i]++;

    return;
}

// command: D 1
void deleteMax()
{
    if(maxq.empty()) return;

    m[maxq.top()]--;
    maxq.pop();
}

// command: D -1
void deleteMin()
{
    if(minq.empty()) return;

    m[minq.top()]--;
    minq.pop();
}

void deleteDupl()
{
    while(!maxq.empty() && !m[maxq.top()]) maxq.pop();
    while(!minq.empty() && !m[minq.top()]) minq.pop();

    return;
}

int main()
{
    fastio();
    
    cin >> T;
    for(int tc = 0; tc < T; tc++) 
    {
        reset();

        cin >> k;
        for(int i = 0; i < k; i++)
        {            
            char command;
            int num;
            cin >> command >> num;
            
            if(command == 'I') insert(num);
            if(command == 'D') 
            {
                if(num == 1) deleteMax();
                if(num == -1) deleteMin();
                deleteDupl();
            }
        }

        if(maxq.empty() || minq.empty()) cout << "EMPTY\n";
        else cout << maxq.top() << " " << minq.top() << "\n";
    }
    
    return 0;
}