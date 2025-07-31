#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v(9), ans;
vector<bool> mask(9);

int main()
{
    for(int i = 0; i < 9; i++) cin >> v[i];
    for(int i = 0; i < 2; i++) mask[i] = true;

    sort(mask.begin(), mask.end());

    do
    {
        int sum = 0;
        for(int i = 0; i < 9; i++) 
        {
            if(mask[i]) continue;
            sum += v[i];
        }

        if(sum == 100) 
        {
            for(int i = 0; i < 9; i++)
            {
                if(mask[i]) continue;
                ans.push_back(v[i]);
            }

            break;
        }

    } while(next_permutation(mask.begin(), mask.end()));

    sort(ans.begin(), ans.end());
    for(auto a:ans) cout << a << "\n";

    return 0;
}