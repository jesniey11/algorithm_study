#include<iostream>

using namespace std;

int main()
{
    while(true)
    {
        char board[3][3];
        string str;

        cin >> str;
        if(str == "end") break;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++) 
            {
                board[i][j] = str.at(i*3+j);
            }
        }
        
        // X, O 개수
        int X = 0, O = 0; 
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == 'X') X++;
                if(board[i][j] == 'O') O++;
            }
        }

        bool flag = true;
        int winX = 0, winO = 0;

        // 대각선
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
        {
            if(board[0][0] == 'X') winX++;
            if(board[0][0] == 'O') winO++;
        }

        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
        {
            if(board[0][2] == 'X') winX++;
            if(board[0][2] == 'O') winO++;
        }

        for(int i = 0; i < 3; i++)
        {
            // 가로
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                if(board[i][0] == 'X') winX++;
                if(board[i][0] == 'O') winO++;
            }

            // 세로
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            {
                if(board[0][i] == 'X') winX++;
                if(board[0][i] == 'O') winO++;
            }
        }

        // 이상한 게임
        if(X < O || O+1 < X) flag = false; // X, O 개수 이상

        if(0 < winX && 0 < winO) flag = false; // 승자가 둘
        if(0 < winX && X != O+1) flag = false; // X승, 개수 이상
        if(0 < winO && X != O) flag = false; // O승, 개수 이상

        if(winX == 0 && winO == 0 && X+O != 9) flag = false; // 무승부인데 판 다 안참

        if(flag) cout << "valid" << endl;
        else cout << "invalid" << endl;
    }

    return 0;
}