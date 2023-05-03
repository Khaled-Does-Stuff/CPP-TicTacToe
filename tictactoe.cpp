#include <iostream>

using namespace std;
void printCurrentGameState();
void takeInput();
bool gameOver();
string getWinPlayer();

inline bool theyAreSame(string x, string y, string z) {
    return (x == y && y == z);
}

string gameBoard[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
bool playerOne = true;

int main() {
    do {
        printCurrentGameState();
        takeInput();
    } while (getWinPlayer() == "");

    printCurrentGameState();
    cout
        << endl
        << getWinPlayer() << " Won";

    return 0;
}

void printCurrentGameState() {
    // TODO: Hard to read

    cout << endl;
    cout << gameBoard[0] << " | " << gameBoard[1] << " | " << gameBoard[2] << endl;
    cout << "---------" << endl;
    cout << gameBoard[3] << " | " << gameBoard[4] << " | " << gameBoard[5] << endl;
    cout << "_________" << endl;
    cout << gameBoard[6] << " | " << gameBoard[7] << " | " << gameBoard[8] << endl;
    cout << endl;
}

void takeInput() {
    cout << "Please give input: (Example: 3 or 1), Player "
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
    // Horizontal checks
    if (theyAreSame(gameBoard[0], gameBoard[1], gameBoard[2]))
        return gameBoard[0];

    if (theyAreSame(gameBoard[3], gameBoard[4], gameBoard[5]))
        return gameBoard[3];

    if (theyAreSame(gameBoard[6], gameBoard[7], gameBoard[8]))
        return gameBoard[6];

    // Vertical checks
    if (theyAreSame(gameBoard[0], gameBoard[3], gameBoard[6]))
        return gameBoard[0];

    if (theyAreSame(gameBoard[1], gameBoard[4], gameBoard[7]))
        return gameBoard[1];

    if (theyAreSame(gameBoard[2], gameBoard[5], gameBoard[8]))
        return gameBoard[2];

    // Corner checks

    if (theyAreSame(gameBoard[0], gameBoard[4], gameBoard[8]))
        return gameBoard[0];

    if (theyAreSame(gameBoard[2], gameBoard[4], gameBoard[6]))
        return gameBoard[2];

    for (string val : gameBoard) {
        if (val != "X" && val != "O") return "";
    }

    return "Nobody";
}
