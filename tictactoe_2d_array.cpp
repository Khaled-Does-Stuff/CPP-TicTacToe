#include <iostream>
#include <limits>

using namespace std;
void printCurrentGameState();
void takeInput();
bool gameOver();
string getWinPlayer();

inline bool theyAreSame(string x, string y, string z) {
    return (x == y && y == z);
}

// It's too much unnecessary work
// if I use 2d array
string gameBoard[3][3] = {{"1", "2", "3"},
                          {"4", "5", "6"},
                          {"7", "8", "9"}};
bool playerOne = true;

// Color taken from:  https://stackoverflow.com/a/45300654/16867144
const string X = "\033[1;31;49mX\033[0m";
const string O = "\033[1;32;49mO\033[0m";

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
    // Clears the console (in linux/win11)
    // https://stackoverflow.com/a/43884673/16867144
    cout << "\033c" << endl;

    cout << " " << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << endl;
    cout << endl;
}

void takeInput() {
    cout << "Please give input: (Range: 1 to 9), Player "
         << (playerOne ? X : O)
         << ": ";

    int input;
    cin >> input;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Try again." << endl;

        takeInput();
        return;
    }

    if (input < 1 || input > 9) {
        cout << "Invalid input. Try again." << input << endl;
        takeInput();
        return;
    }

    // thanks Abbasy. Very cool big brain math
    int row = ((input - 1) / 3);
    int column = ((input - 1) % 3);

    if (gameBoard[row][column] == X || gameBoard[row][column] == O) {
        cout << "Invalid input. Try again." << endl;
        takeInput();
        return;
    }

    gameBoard[row][column] = (playerOne ? X : O);
    playerOne = !playerOne;
}

string getWinPlayer() {
    // Horizontal checks
    if (theyAreSame(gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]))
        return gameBoard[0][0];

    if (theyAreSame(gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]))
        return gameBoard[1][0];

    if (theyAreSame(gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]))
        return gameBoard[2][0];

    // Vertical checks
    if (theyAreSame(gameBoard[0][0], gameBoard[1][0], gameBoard[2][0]))
        return gameBoard[0][0];

    if (theyAreSame(gameBoard[0][1], gameBoard[1][1], gameBoard[2][1]))
        return gameBoard[0][1];

    if (theyAreSame(gameBoard[0][2], gameBoard[1][2], gameBoard[2][2]))
        return gameBoard[0][2];

    // Corner checks
    if (theyAreSame(gameBoard[0][0], gameBoard[1][1], gameBoard[2][2]))
        return gameBoard[0][0];

    if (theyAreSame(gameBoard[0][2], gameBoard[1][1], gameBoard[2][0]))
        return gameBoard[0][2];

    // Still has input left
    // Just use "auto" https://stackoverflow.com/a/16509095/16867144
    for (auto& arr : gameBoard) {
        for (string val : arr) {
            if (val != X && val != O) return "";
        }
    }

    return "Nobody";  // Draw
}
