#include<iostream>

using namespace std;

char board[3][3];

int check(char winner)
{
    int wins = 0;

    // 가로 / 세로
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == winner && board[i][1] == winner && board[i][2] == winner) wins++;
        if(board[0][i] == winner && board[1][i] == winner && board[2][i] == winner) wins++;
    }
    // 대각선
    if(board[0][0] == winner && board[1][1] == winner && board[2][2] == winner) wins++;
    if(board[0][2] == winner && board[1][1] == winner && board[2][0] == winner) wins++;

    return wins;
}

int main()
{
    while(true)
    {
        int X = 0, O = 0;
        string str;
        cin >> str;

        if(str == "end") break;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++) 
            {
                board[i][j] = str.at(i*3+j);

                if(board[i][j] == 'X') X++;
                if(board[i][j] == 'O') O++;
            }
        }
        
        int winX = check('X');
        int winO = check('O');

        bool isVaild = true;

        // 이상한 게임
        if(X < O || O+1 < X) isVaild = false; // X, O 개수 이상

        if(0 < winX && 0 < winO) isVaild = false; // 승자가 둘
        if(0 < winX && X != O+1) isVaild = false; // X승, 개수 이상
        if(0 < winO && X != O) isVaild = false; // O승, 개수 이상

        if(winX == 0 && winO == 0 && X+O != 9) isVaild = false; // 안 끝남

        cout << (isVaild ? "valid" : "invalid") << endl;
    }

    return 0;
}