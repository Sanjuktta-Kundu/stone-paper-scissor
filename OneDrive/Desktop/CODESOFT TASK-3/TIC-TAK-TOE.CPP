#include <iostream>

using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];

            if(j < 2)
                cout << " | ";
        }
        cout << "\n";

        if(i < 2)
            cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin() {

    // Rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void playerMove() {
    int choice;
    int row, col;

    cout << "Player " << currentPlayer
         << ", enter your move (1-9): ";
    cin >> choice;

    row = (choice - 1) / 3;
    col = (choice - 1) % 3;

    if(board[row][col] != 'X' &&
       board[row][col] != 'O') {

        board[row][col] = currentPlayer;

        currentPlayer =
            (currentPlayer == 'X') ? 'O' : 'X';
    }
    else {
        cout << "Invalid move! Try again.\n";
        playerMove();
    }
}

void resetBoard() {
    char value = '1';

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = value++;
        }
    }

    currentPlayer = 'X';
}

int main() {

    char playAgain;

    do {
        resetBoard();

        while(true) {

            displayBoard();

            playerMove();

            displayBoard();

            char winner =
                (currentPlayer == 'X') ? 'O' : 'X';

            if(checkWin()) {
                cout << "Player "
                     << winner
                     << " Wins!\n";
                break;
            }

            if(checkDraw()) {
                cout << "Game Draw!\n";
                break;
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' ||
            playAgain == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}