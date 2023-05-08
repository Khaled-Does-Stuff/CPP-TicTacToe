#include <iostream>
#include <limits>

#include "colormod.h"

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

const string X = "X";
const string O = "O";

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

    // Clears the console (in linux/win11)
    // https://stackoverflow.com/a/43884673/16867144
    cout << "\033c" << endl;

    cout << gameBoard[0] << " | " << gameBoard[1] << " | " << gameBoard[2] << endl;
    cout << "---------" << endl;
    cout << gameBoard[3] << " | " << gameBoard[4] << " | " << gameBoard[5] << endl;
    cout << "_________" << endl;
    cout << gameBoard[6] << " | " << gameBoard[7] << " | " << gameBoard[8] << endl;
    cout << endl;
}

void takeInput() {
    cout << "Please give input: (Range: 1 to 9), Player "
         << (playerOne ? X : O)
         << ": ";

    int input;
    cin >> input;

    // TODO Validate numeric input
    // while (cin.fail()) {
    //     cin.clear();
    //     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //     takeInput();
    // }

    if (input < 1 || input > 9 ||
        gameBoard[input - 1] == X || gameBoard[input - 1] == O) {
        cout << "Invalid input. Try again." << endl;
        takeInput();
        return;
    }

    gameBoard[input - 1] = (playerOne ? X : O);
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

    // Still has input left
    for (string val : gameBoard) {
        if (val != "X" && val != "O") return "";
    }

    return "Nobody";  // Draw
}
