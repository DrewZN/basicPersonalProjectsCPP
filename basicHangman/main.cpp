#include <iostream>
#include <string>
#include <vector>

void displayHangman(std::vector<std::string>);
bool checkForLetter(char, std::string, std::vector<char>&, std::vector<char>&);
void updateHangman(std::vector<std::string> &, std::vector<std::string>, int);
void createLetterLines(std::vector<char> &, std::string);

int main() {
    // Important Variables
    std::vector<std::string> templateBoard = {"--------|", "   |    |", "   o    |", "  /|\\   |", "   |    |", "   /\\   |", "        |", "--------|"};
    std::vector<std::string> gameBoard = {"--------|", "        |", "        |", "        |", "        |", "        |", "        |", "--------|"};
    std::vector<char> correctLetters;
    std::vector<char> lettersOfAns;
    int numErrors = 0;
    std::string ans = "humility";
    int maxErrors = 5;

    while (true) {
        displayHangman(gameBoard);
        createLetterLines(lettersOfAns, ans);
        std::cout << std::endl;

        for (int i = 0; i < ans.length(); i++) {
            std::cout << lettersOfAns[i] << " ";
        }
        std::cout << std::endl;

        char guess;
        std::cout << "\nGuess a letter: ";
        std::cin >> guess;

        if (checkForLetter(guess, ans, correctLetters, lettersOfAns)) {
            displayHangman(gameBoard);
            std::cout << "\nLetters found: ";
            for (int i = 0; i < correctLetters.size(); i++) {
                std::cout << correctLetters[i] << " ";
            }
            std::cout << std::endl;
        }
        else {
            numErrors++;
            if (numErrors == maxErrors) {
                updateHangman(gameBoard, templateBoard, numErrors);
                displayHangman(gameBoard);
                std::cerr << "Game Over!\n";
                break;
            }
            updateHangman(gameBoard, templateBoard, numErrors);
        }
    }
    return 0;
}

void displayHangman(std::vector<std::string> gameBoard) {
    for (const auto & i : gameBoard) {
        std::cout << i << std::endl;
    }
}

bool checkForLetter(char guess, std::string ans, std::vector<char> &correctLetters, std::vector<char> &lettersOfAns) {
    bool found = false;
    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] == guess) {
            correctLetters.push_back(guess);
            lettersOfAns[i] = guess;
            found = true;
        }
    }
    return found;
}

void updateHangman(std::vector<std::string> &gameBoard, std::vector<std::string> templateBoard, int numErrors) {
    for (int i = 1; i < numErrors + 1; i++) {
        gameBoard[i] = templateBoard[i];
    }
}

void createLetterLines(std::vector<char> &lettersOfAns, std::string ans) {
    for (int i = 1; i < ans.length(); i++) {
        lettersOfAns.push_back('-');
    }
}