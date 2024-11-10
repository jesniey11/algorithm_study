#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
vector<int> num;

int find(int i)
{
    int start = 0;
    int end = N-1;

    while(start>=0 && end<N && start<end)
    {
        int sum = num[start]+num[end];

        if(i==end || sum>num[i]) end -= 1;
        else if(i==start || sum<num[i]) start += 1;
        else return 1;
    }
    return 0;
}

int main()
{
    cin >> N;
    num = vector<int>(N);

    for(int i=0; i<N; i++)
    {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    for(int i=0; i<N; i++)
    {
        ans+=find(i);
    }

    cout << ans;
    return 0;
}