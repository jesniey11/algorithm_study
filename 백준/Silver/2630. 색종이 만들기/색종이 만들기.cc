#include<iostream>
#include<vector>

using namespace std;

int N, white, blue;
int paper[129][129];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    white = 0; blue = 0;
}

void conquer(int x, int y, int range)
{
    if(range < 1) return;
    int color = paper[x][y];

    for(int i = x; i < x+range; i++)
    {
        for(int j = y; j < y+range; j++)
        {
            // 제일 첫칸이랑 비교
            if(paper[i][j] != color)
            {
                conquer(x, y, range/2);
                conquer(x, y+range/2, range/2);
                conquer(x+range/2, y, range/2);
                conquer(x+range/2, y+range/2, range/2);

                return;
            }
        }
    }

    if(color == 0) white++;
    if(color == 1) blue++;

    return;
}

int main()
{
    input();
    conquer(0, 0, N);

    cout << white << "\n" << blue;
    return 0;
} 
