#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Function Prototypes
void displayHangman(std::vector<std::string>);                                  // Displays current state of hangman board
bool checkForLetter(char, std::string, std::vector<char>&, std::vector<char>&); // Checks if letter exists in answer word
void updateHangman(std::vector<std::string> &, int);  // Updates hangman board with limbs as you get more letters wrong
void createLetterLines(std::vector<char> &, std::string);                       // Creates letter lines (-) for each character in the answer
bool checkIfGameCompleted(std::string, std::vector<char>);                      // Checks if letters in the lettersOfAns vector match the answer
std::string generateWord();                                        // Randomly Selects a Word From the File

int main() {
    // Print Developer Info
    std::cout << "Hangman: made by Dominic Andrew Bernardino\n";
    // Important Variables
    std::vector<std::string> templateBoard = {"--------|", "   |    |", "   o    |", "  /|\\   |", "   |    |", "   /\\   |", "        |", "--------|"};
    std::vector<std::string> gameBoard = {"--------|", "        |",  "        |", "        |", "        |", "        |", "        |", "--------|"};
    std::vector<char> correctLetters;
    std::vector<char> lettersOfAns;
    std::vector<char> incorrectLetters;
    int numErrors = 0;
    std::string ans = generateWord(); // Generate Random Word From File
    int maxErrors = 7;
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
        // Show Incorrectly Guessed Letters
        if (incorrectLetters.size() > 0) {
            // Sort Alphabetically
            for (int i = 0; i < incorrectLetters.size(); i++) {
                for (int j = i + 1; j < incorrectLetters.size(); j++) {
                    if (incorrectLetters[j] < incorrectLetters[i]) {
                        char tempC = incorrectLetters[j];
                        incorrectLetters[j] = incorrectLetters[i];
                        incorrectLetters[i] = tempC;
                    }
                }
            }
            // Now Display Incorrectly Guessed Letters
            std::cout << "\nIncorrect Letters Already Guessed: ";
            for (int i = 0; i < incorrectLetters.size(); i++) {
                std::cout << incorrectLetters[i] << " ";
            }
            std::cout << std::endl;
        }
        // Ask For Guess
        char guess;
        std::cout << "\nGuess a letter: ";
        std::cin >> guess;
        // Check If Guessed Character Matches Any Letter in the Answer
        if (checkForLetter(guess, ans, correctLetters, lettersOfAns)) {
            // If Letters Guessed Matches the Answer
            std::cout << std::endl;
        }
        else {
            // Increases Number of Errors
            numErrors++;
            // Check if Guessed Letter Is Already In "incorrectLetters" Vector
            bool notInVector = true;
            for (int i = 0; i < incorrectLetters.size(); i++) {
                if (guess == incorrectLetters[i]) {
                    notInVector = false;
                }
            }
            // Add Incorrect Guess to "incorrectLetters" Vector
            if (notInVector) {
                incorrectLetters.push_back(guess);
            }
            // Checks if Number of Errors Is Equivalent to Maximum Number of Incorrect Guesses
            if (numErrors == maxErrors) {
                // Updates and Shows Full Hangman Board
                updateHangman(gameBoard, numErrors);
                displayHangman(gameBoard);
                // Game Over (Lose)
                std::cerr << "Game Over! You Lose!\n";
                std::cerr << "The Correct Word Was: " << ans <<  std::endl;
                break;
            }
            // Updates Hangman Board From Incorrect Guess
            updateHangman(gameBoard, numErrors);
            std::cout << std::endl;
        }
        // Every Guess Increases Number of Tries
        numTries++;
        // If You Guess All The Correct Characters
        if (checkIfGameCompleted(ans, lettersOfAns)) {
            // Displays Current Board State
            displayHangman(gameBoard);
            // Displays Correct Letters
            std::cout << std::endl;
            for (int i = 0; i < ans.length(); i++) {
                std::cout << lettersOfAns[i] << " ";
            }
            // Game Over (Win)
            std::cout << "\n\nGame Over! You Win!\n"
                         "It Took You " << numTries << " Tries!\n";
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

void updateHangman(std::vector<std::string> &gameBoard, int numErrors) {
    // Updates Each Row (From Top to Bottom) Depending On Number of Errors
    switch (numErrors) {
        case 1: {
            gameBoard = {"--------|", "   |    |",  "        |", "        |", "        |", "        |", "        |", "--------|"};
            break;
        }
        case 2: {
            gameBoard = {"--------|", "   |    |",  "   o    |", "        |", "        |", "        |", "        |", "--------|"};
            break;
        }
        case 3: {
            gameBoard = {"--------|", "   |    |",  "   o    |", "   |    |", "        |", "        |", "        |", "--------|"};
            break;
        }
        case 4: {
            gameBoard = {"--------|", "   |    |",  "   o    |", "  /|    |", "        |", "        |", "        |", "--------|"};
            break;
        }
        case 5: {
            gameBoard = {"--------|", "   |    |",  "   o    |", "  /|\\   |", "        |", "        |", "        |", "--------|"};
            break;
        }
        case 6: {
            gameBoard = {"--------|", "   |    |",  "   o    |", "  /|\\   |", "   |    |", "  /     |", "        |", "--------|"};
            break;
        }
        case 7: {
            gameBoard = {"--------|", "   |    |",  "   o    |", "  /|\\   |", "   |    |", "  / \\   |", "        |", "--------|"};
            break;
        }
    }
}

void createLetterLines(std::vector<char> &lettersOfAns, std::string ans) {
    // Creates Number of Letters to Guess and Display to Screen
    for (int i = 0; i < ans.length(); i++) {
        lettersOfAns.push_back('_');
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

std::string generateWord() {
    // Open a Word Dictionary File
    std::ifstream readFile("wordDictionary.txt");
    // Create Temporary String Vector to Store Words From File
    std::vector<std::string> tempWords;
    std::string temp;
    // Read To Temporary String Variable, Then Push To Temp String Vector
    while (readFile >> temp) {
        tempWords.push_back(temp);
    }
    // Initialize Random Seed
    std::srand(std::time(nullptr));
    // Generate Random Answer Word Based on Secret Number From 1 to the Number Of Entries In Word Dictionary
    std::string ansG = tempWords[std::rand() % tempWords.size()];
    return ansG;
}