#include <iostream>
#include <string>
#include <vector>

void passwordPrompt(std::vector<std::string>, std::vector<std::string>);
bool ifChecksOut(std::string, std::string, std::vector<std::string>, std::vector<std::string>);

int main() {
    std::vector<std::string> userNames;
    std::vector<std::string> passWords;

    std::cout << "How many users do you want? ";
    int numUsers;
    std::cin >> numUsers;

    for (int i = 0; i < numUsers; i++) {
        std::cout << "Username " << i+1 << ": ";
        std::string temp;
        std::getline(std::cin >> std::ws, temp);
        userNames.push_back(temp);
        std::cout << "Password " << i+1 << ": ";
        std::getline(std::cin >> std::ws, temp);
        passWords.push_back(temp);
    }

    bool quit = false;

    do {
        // Main Menu
        std::cout << "1. Login\n"
                  << "2. Quit\n"
                  << "Option: ";
        int menuOp;
        std::cin >> menuOp;
        if (std::cin.fail()) {
            // Error Checking
            std::cerr << "Error: Invalid Input.\nPlease Try Again.\n";
            std::cin.ignore(256, '\n');
            std::cout << "1. Login\n"
                      << "2. Quit\n"
                      << "Option: ";
            std::cin >> menuOp;
        }
        // Switch Case
        switch(menuOp) {
            case 1: {
                passwordPrompt(userNames, passWords);
                break;
            }
            case 2: {
                quit = true;
                std::cout << "Program is quitting.\n";
                break;
            }
            default: {
                std::cerr << "Error: Invalid Input.\n"
                             "Please Try Again.\n";
                break;
            }
        }

    } while (quit == false);

    return 0;
}

void passwordPrompt(std::vector<std::string> usernames, std::vector<std::string> passwords) {
    std::string userNameTemp, passWordTemp;
    std::cout << "Enter Username: ";
    std::getline(std::cin >> std::ws, userNameTemp);
    std::cout << "Enter Password: ";
    std::getline(std::cin >> std::ws, passWordTemp);
    if (ifChecksOut(userNameTemp, passWordTemp, usernames, passwords)) {
        std::cout << "Yay! You successfully logged in!\n";
    }
    else {
        std::cerr << "Error! Unsuccessful Login.\n";
    }
}

bool ifChecksOut(std::string username, std::string password, std::vector<std::string> usernames, std::vector<std::string> passwords) {
    bool ret = false;
    bool foundU = false, foundP = false, bothBelong = false;
    int indexU, indexP;

    // Find index of username (or if it even exists)
    for (int i = 0; i < usernames.size(); i++) {
        if (usernames[i] == username) {
            foundU = true;
            indexU = i;
        }
    }
    // Find index of password (or if it even exists)
    for (int j = 0; j < passwords.size(); j++) {
        if (passwords[j] == password) {
            foundP = true;
            indexP = j;
        }
    }

    // Check if username belongs to password (and vice versa) using indices
    if (indexU == indexP) {
        bothBelong = true;
    }

    if (foundU && foundP && bothBelong) {
        ret = true;
    }

    return ret;
}