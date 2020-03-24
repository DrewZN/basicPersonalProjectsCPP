#include <iostream>
#include <string>
#include <vector>

void createUser(std::vector<std::string> &, std::vector<std::string> &);
void deleteUser(std::vector<std::string> &, std::vector<std::string> &);
void passwordPrompt(std::vector<std::string>, std::vector<std::string>);
bool ifChecksOut(std::string, std::string, std::vector<std::string>, std::vector<std::string>);

int main() {
    std::vector<std::string> userNames;
    std::vector<std::string> passWords;

    bool quit = false;

    do {
        // Main Menu
        std::cout << "Main Menu:\n"
                  << "1. Login\n"
                  << "2. Create user\n"
                  << "3. Delete user\n"
                  << "4. Quit\n"
                  << "Option: ";
        int menuOp;
        std::cin >> menuOp;
        if (std::cin.fail()) {
            // Error Checking
            std::cerr << "Error: Invalid Input.\nPlease Try Again.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Main Menu:\n"
                      << "1. Login\n"
                      << "2. Create user\n"
                      << "3. Delete user\n"
                      << "4. Quit\n"
                      << "Option: ";
            std::cin >> menuOp;
        }
        // Switch Case
        switch(menuOp) {
            case 1: {
                // Error Checking
                if (userNames.size() == 0 || passWords.size() == 0) {
                    std::cerr << "Error: No usernames nor passwords detected.\n";
                    break;
                }
                passwordPrompt(userNames, passWords);
                break;
            }
            case 2: {
                createUser(userNames, passWords);
                break;
            }
            case 3: {
                // Error Checking
                if (userNames.size() == 0 || passWords.size() == 0) {
                    std::cerr << "Error: No usernames nor passwords detected.\n";
                    break;
                }
                deleteUser(userNames, passWords);
                break;
            }
            case 4: {
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

void createUser(std::vector<std::string> &usernames, std::vector<std::string> &passwords) {
    std::string username, password;
    std::cout << "Enter Username: ";
    std::getline(std::cin >> std::ws, username);
    std::cout << "Enter Password: ";
    std::getline(std::cin >> std::ws, password);

    usernames.push_back(username);
    passwords.push_back(password);

    std::cout << "User \"" << username << "\" Created.\n";
}

void deleteUser(std::vector<std::string> &usernames, std::vector<std::string> &passwords) {
    // List usernames to delete
    std::cout << "Usernames in System: \n";
    for (int i = 0; i < usernames.size(); i++) {
        std::cout << i << "\t" << usernames[i] << "\n";
    }
    std::cout << 999 << "\t" << "Exit\n";
    // Ask for which index to delete
    std::cout << "Which **number** of the username do you wish to delete? ";
    int toDelete;
    std::cin >> toDelete;
    // Error checking
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Which **number** of the username do you wish to delete? ";
        std::cin >> toDelete;
    }
    // If '999' (Exit)
    if (toDelete == 999) {
        return;
    }
    // Check if number is within either vector
    if (toDelete + 1 > usernames.size() || toDelete < 0) {\
        std::cerr << "Error: Invalid Number.\n";
        return;
    }
    // Delete username **and** password from arrays according to index
    usernames.erase(usernames.begin() + toDelete);
    passwords.erase(passwords.begin() + toDelete);

    std::cout << "User has been deleted.\n";
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