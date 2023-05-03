#include <iostream>

using namespace std;
void printCurrentGameState();
void takeInput();
bool gameOver();
string getWinPlayer();

string gameBoard[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
bool playerOne = true;

int main() {
    do {
        printCurrentGameState();
        takeInput();
    } while (getWinPlayer() == "");

    cout << endl
         << getWinPlayer() << " Won";

    return 0;
}

void printCurrentGameState() {
    cout << gameBoard[0] << " | " << gameBoard[1] << " | " << gameBoard[2] << endl;
    cout << "---------" << endl;
    cout << gameBoard[3] << " | " << gameBoard[4] << " | " << gameBoard[5] << endl;
    cout << "_________" << endl;
    cout << gameBoard[6] << " | " << gameBoard[7] << " | " << gameBoard[8] << endl;
}

void takeInput() {
    cout << endl
         << "Please give input: (Example: 3 or 1), Player "
         << (playerOne ? "X" : "O")
         << ": ";

    int input;
    cin >> input;
    // TODO Validate input
    // TODO Avoid duplicate input

    gameBoard[input - 1] = (playerOne ? "X" : "O");
    playerOne = !playerOne;
}

string getWinPlayer() {
    if ((gameBoard[0] == gameBoard[1]) && (gameBoard[1] == gameBoard[2]))
        return gameBoard[0];

    for (string val : gameBoard) {
        if (val != "X" && val != "O") return "";
    }

    return "Nobody";
}