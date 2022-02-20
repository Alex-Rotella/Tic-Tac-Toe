#include <iostream>

using namespace std;

char gameboard[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';
int moveCount = 0;
char playAgain;

void drawboard(){
    cout << " -------------" << endl;
    cout << " | " << gameboard[0][0] << " | " << gameboard[0][1] << " | " << gameboard[0][2] << " | " << endl;
    cout << " -------------" << endl;
    cout << " | " << gameboard[1][0] << " | " << gameboard[1][1] << " | " << gameboard[1][2] << " | " << endl;
    cout << " -------------" << endl;
    cout << " | " << gameboard[2][0] << " | " << gameboard[2][1] << " | " << gameboard[2][2] << " | " << endl;
    cout << " -------------" << endl;
}

char changePlayer() {
    if(player == 'X'){
        player = 'O';
        return 'X';
    }
    else {
        player = 'X';
        return 'O';
    }
}

void userMove() {
    char choice;
    bool valid = false;
    do {
        cout << "Enter the number where you would like to place your selection" << endl;
        cin >> choice;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(gameboard[i][j] == choice) {
                    gameboard[i][j] = changePlayer();
                    cout << "Found" << endl;
                    valid = true;
                    moveCount++;
                    break;
                }
                
            }     
        }
        if(valid == false) {
            cout << "Spot has already been chosen, pick again" << endl;
        }
    } while(valid == false);
    
}

char winner(){
    // X wins
    if (gameboard[0][0] == 'X' && gameboard[0][1] == 'X' && gameboard[0][2] == 'X')
        return 'X';
    if (gameboard[1][0] == 'X' && gameboard[1][1] == 'X' && gameboard[1][2] == 'X')
        return 'X';
    if (gameboard[2][0] == 'X' && gameboard[2][1] == 'X' && gameboard[2][2] == 'X')
        return 'X';
    if (gameboard[0][0] == 'X' && gameboard[1][0] == 'X' && gameboard[2][0] == 'X')
        return 'X';
    if (gameboard[0][1] == 'X' && gameboard[1][1] == 'X' && gameboard[2][1] == 'X')
        return 'X';
    if (gameboard[0][2] == 'X' && gameboard[1][2] == 'X' && gameboard[2][2] == 'X')
        return 'X';
    if (gameboard[0][0] == 'X' && gameboard[1][1] == 'X' && gameboard[2][2] == 'X')
        return 'X';
    if (gameboard[2][0] == 'X' && gameboard[1][1] == 'X' && gameboard[0][2] == 'X')
        return 'X';
    // O wins
    if (gameboard[0][0] == 'O' && gameboard[0][1] == 'O' && gameboard[0][2] == 'O')
        return 'O';
    if (gameboard[1][0] == 'O' && gameboard[1][1] == 'O' && gameboard[1][2] == 'O')
        return 'O';
    if (gameboard[2][0] == 'O' && gameboard[2][1] == 'O' && gameboard[2][2] == 'O')
        return 'O';
    if (gameboard[0][0] == 'O' && gameboard[1][0] == 'O' && gameboard[2][0] == 'O')
        return 'O';
    if (gameboard[0][1] == 'O' && gameboard[1][1] == 'O' && gameboard[2][1] == 'O')
        return 'O';
    if (gameboard[0][2] == 'O' && gameboard[1][2] == 'O' && gameboard[2][2] == 'O')
        return 'O';
    if (gameboard[0][0] == 'O' && gameboard[1][1] == 'O' && gameboard[2][2] == 'O')
        return 'O';
    if (gameboard[2][0] == 'O' && gameboard[1][1] == 'O' && gameboard[0][2] == 'O')
        return 'O';
 
    return '1';
}

void newGame() {
    int counter = 1;
    for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                gameboard[i][j] = '0' + counter;
                counter++;
            }     
        }
    moveCount = 0;
    player = 'X';
}

int replay() {
    cout << "Would you like to play again? (Y/N)" << endl;
    cin >> playAgain;
    if(playAgain == 'Y' || playAgain == 'y') {
        newGame();
        drawboard();
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    drawboard();
    while (1) {
        userMove();
        drawboard();
        if (winner() == 'X') {
            cout << "X wins!" << endl;
            if(replay() == 0){
                return 0;
            }
        }
        else if (winner() == 'O') {
            cout << "O wins!" << endl;
            if(replay() == 0){
                return 0;
            }
        }
        if(moveCount >= 9){
            cout << "The game is a draw!" << endl;
            if(replay() == 0){
                return 0;
            }
        }
    }
    return 0;
}