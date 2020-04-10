#include <iostream>
#include <string>
#include <vector>

// Fraction Prototypes
void displayHangman(std::vector<std::string>);                                  // Displays current state of hangman board
bool checkForLetter(char, std::string, std::vector<char>&, std::vector<char>&); // Checks if letter exists in answer word
void updateHangman(std::vector<std::string> &, std::vector<std::string>, int);  // Updates hangman board with limbs as you get more letters wrong
void createLetterLines(std::vector<char> &, std::string);                       // Creates letter lines (-) for each character in the answer
bool checkIfGameCompleted(std::string, std::vector<char>);                      // Checks if letters in the lettersOfAns vector match the answer

int main() {
    // Important Variables
    std::vector<std::string> templateBoard = {"--------|", "   |    |", "   o    |", "  /|\\   |", "   |    |", "   /\\   |", "        |", "--------|"};
    std::vector<std::string> gameBoard = {"--------|", "        |", "        |", "        |", "        |", "        |", "        |", "--------|"};
    std::vector<char> correctLetters;
    std::vector<char> lettersOfAns;
    int numErrors = 0;
    std::string ans = "book";
    int maxErrors = 5;
    int numTries = 0;
    createLetterLines(lettersOfAns, ans);
    // Infinite Loop Until Win or Lose
    while (true) {
        // Display Current State of Hangman Board
        displayHangman(gameBoard);
        std::cout << std::endl;
        // Display Current Letter Lines
        for (int i = 0; i < ans.length(); i++) {
            std::cout << lettersOfAns[i] << " ";
        }
        std::cout << std::endl;
        // Ask For Guess
        char guess;
        std::cout << "\nGuess a letter: ";
        std::cin >> guess;
        // Check If Guessed Character Matches Any Letter in the Answer
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
                std::cerr << "Game Over! You Lose!\n";
                break;
            }
            updateHangman(gameBoard, templateBoard, numErrors);
        }
        // Every Guess Increases Number of Tries
        numTries++;
        // If Letters Guessed Matches the Answer
        if (checkIfGameCompleted(ans, lettersOfAns)) {
            std::cout << "Game Over! You Win!\n"
                         "It Took You" << numTries << " Tries!\n";
            break;
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
    for (int i = 0; i < ans.length(); i++) {
        lettersOfAns.push_back('-');
    }
}

bool checkIfGameCompleted(std::string ans, std::vector<char> lettersOfAns) {
    bool ret = true;

    for (int i = 0; i < lettersOfAns.size(); i++) {
        if (ans[i] != lettersOfAns[i]) {
            return false;
        }
    }

    return true;
}