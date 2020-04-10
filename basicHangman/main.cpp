#include <iostream>
#include <string>
#include <vector>

// Function Prototypes
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
            // Displays Current Board State
            displayHangman(gameBoard);
            // Displays Correct Guessed Letters
            std::cout << "\nLetters found: ";
            for (int i = 0; i < correctLetters.size(); i++) {
                std::cout << correctLetters[i] << " ";
            }
            std::cout << std::endl;
        }
        else {
            // Increases Number of Errors
            numErrors++;
            // Checks if Number of Errors Is Equivalent to Maximum Number of Incorrect Guesses
            if (numErrors == maxErrors) {
                // Updates and Shows Full Hangman Board
                updateHangman(gameBoard, templateBoard, numErrors);
                displayHangman(gameBoard);
                // Game Over (Lose)
                std::cerr << "Game Over! You Lose!\n";
                break;
            }
            // Updates Hangman Board From Incorrect Guess
            updateHangman(gameBoard, templateBoard, numErrors);
        }
        // Every Guess Increases Number of Tries
        numTries++;
        // If Letters Guessed Matches the Answer
        if (checkIfGameCompleted(ans, lettersOfAns)) {
            // Game Over (Win)
            std::cout << "Game Over! You Win!\n"
                         "It Took You" << numTries << " Tries!\n";
            break;
        }
    }
    return 0;
}

// Function Definitions
void displayHangman(std::vector<std::string> gameBoard) {
    // Displays Current Board State
    for (const auto & i : gameBoard) {
        std::cout << i << std::endl;
    }
}

bool checkForLetter(char guess, std::string ans, std::vector<char> &correctLetters, std::vector<char> &lettersOfAns) {
    bool found = false;
    // Compares Guessed Letter With Each of the Correct Answer's Characters
    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] == guess) {
            // Adds Guessed Letter to "Correct Letters" Vector
            correctLetters.push_back(guess);
            // Replaces (-) In "lettersOfAns" To Correct Letter
            lettersOfAns[i] = guess;
            found = true;
        }
    }
    return found;
}

void updateHangman(std::vector<std::string> &gameBoard, std::vector<std::string> templateBoard, int numErrors) {
    // Updates Each Row (From Top to Bottom) Depending On Number of Errors
    for (int i = 1; i < numErrors + 1; i++) {
        gameBoard[i] = templateBoard[i];
    }
}

void createLetterLines(std::vector<char> &lettersOfAns, std::string ans) {
    // Creates Number of Letters to Guess and Display to Screen
    for (int i = 0; i < ans.length(); i++) {
        lettersOfAns.push_back('-');
    }
}

bool checkIfGameCompleted(std::string ans, std::vector<char> lettersOfAns) {
    bool ret = true;
    // Checks if All Letters in "lettersOfAns" Match the Correct Answer
    for (int i = 0; i < lettersOfAns.size(); i++) {
        if (ans[i] != lettersOfAns[i]) {
            return false;
        }
    }
    return true;
}