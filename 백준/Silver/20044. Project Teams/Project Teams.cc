#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n, ans = 987654321;
    vector<int> student;
    cin >> n;
    
    for(int i = 0; i < 2*n; i++)
    {
        int s; cin >> s;
        student.push_back(s);
    }

    sort(student.begin(), student.end());

    int e = (2*n)-1;
    for(int i = 0; i < n; i++) ans = min(ans, student[i] + student[e-i]);

    cout << ans;
    return 0;
}