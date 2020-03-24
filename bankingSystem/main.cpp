#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class bankAcc {
private:
    string name;
    int PIN;
    int accNum;
    double accBal = 0;
public:
    void setName(std::string);
    void setBal(double);
    void setAccNum(int);
    void setPIN(int);

    std::string getName() const;
    double getBal() const;
    int getAccNum() const;
    int getPIN() const;

    void displayBal() const;
    void deposit();
    void withdraw();
};

void bankAcc::setName(std::string nameTemp) {
    this->name = nameTemp;
}

void bankAcc::setBal(double balTemp) {
    this->accBal = balTemp;
}

void bankAcc::setAccNum(int accNumTemp) {
    this->accNum = accNumTemp;
}

void bankAcc::setPIN(int tempPIN) {
    this->PIN = tempPIN;
}

std::string bankAcc::getName() const {
    return this->name;
}

double bankAcc::getBal() const {
    return this->accBal;
}

int bankAcc::getAccNum() const {
    return this->accNum;
}

int bankAcc::getPIN() const {
    return this->PIN;
}

void bankAcc::displayBal() const {
    if (this->accBal <= 0) {
        std::cerr << "Error: Non-existent/Invalid Balance Detected.\n";
        return;
    }
    std::cout << "Account Balance: \n";
    std::cout << this->name << "\t$" << this->accBal << "\n";
}

void bankAcc::deposit() {
    double depAmount;
    std::cout << "How much would you like to deposit? ";
    std::cin >> depAmount;
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "How much would you like to deposit? ";
        std::cin >> depAmount;
    }
    if (depAmount <= 0) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "How much would you like to deposit? ";
        std::cin >> depAmount;
    }
    this->accBal += depAmount;
    std::cout << "Successfully deposited $" << depAmount << " to account.\n";
    std::cout << "Current Balance: $" << this->accBal << "\n";
}

void bankAcc::withdraw() {
    if (this->accBal <= 0) {
        std::cerr << "Error: Non-existent/Invalid Balance Detected.\n";
        return;
    }
    double withAmount;
    std::cout << "How much would you like to withdraw? ";
    std::cin >> withAmount;
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "How much would you like to withdraw? ";
        std::cin >> withAmount;
    }
    if (withAmount <= 0) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "How much would you like to withdraw? ";
        std::cin >> withAmount;
    }
    this->accBal -= withAmount;
    std::cout << "Successfully withdrew #" << withAmount << " from account.\n";
    std::cout << "Current Balance: #" << this->accBal << "\n";
}

void createNewAccount(vector<bankAcc> &);
void deleteAccount(vector<bankAcc> &);
void mainMenu(vector<bankAcc> &);
void saveToFile(vector<bankAcc>);
void readFromFile(vector<bankAcc> &);
void loginSystem(vector<bankAcc> &);

int main() {
    std::cout << std::fixed << std::setprecision(2) << std::showpoint;

    vector<bankAcc> bankAccounts;

    mainMenu(bankAccounts);

    return 0;
}

void mainMenu(vector<bankAcc> &bankAccounts) {
    bool quit = false;
    do {
        int menuOption;
        cout << "--------------------------" << endl;
        cout << "Welcome to Bank Bernardino" << endl;
        cout << "--------------------------" << endl;
        cout << "01. Open New Account\n";
        cout << "02. Delete Account\n";
        cout << "03. Login to Account\n";
        cout << "04. Save to File\n";
        cout << "05. Read from File\n";
        cout << "06. Exit\n";
        cout << "---------------------------" << endl;
        cout << "Option: ";
        cin >> menuOption;
        if (cin.fail()) {
            cerr << "Error: Invalid Option.\n";
            cin.clear();
            cin.ignore(256, '\n');
            cout << "--------------------------" << endl;
            cout << "Welcome to Bank Bernardino" << endl;
            cout << "--------------------------" << endl;
            cout << "01. Open New Account\n";
            cout << "02. Delete Account\n";
            cout << "03. Login to Account\n";
            cout << "04. Save to File\n";
            cout << "05. Read from File\n";
            cout << "06. Exit\n";
            cout << "---------------------------" << endl;
            cout << "Option: ";
            cin >> menuOption;
        }
        switch(menuOption) {
            case 1:
                createNewAccount(bankAccounts);
                break;
            case 2:
                deleteAccount(bankAccounts);
                break;
            case 3:
                loginSystem(bankAccounts);
                break;
            case 4:
                saveToFile(bankAccounts);
                break;
            case 5:
                readFromFile(bankAccounts);
                break;
            case 6:
                return;
            default:
                cerr << "Error: Unknown Option.\n";
                cerr << "Please try again.\n";
                break;
        }
    } while (quit == false);
}

void createNewAccount(vector<bankAcc> &bankAccounts) {
    bankAcc temp;
    std::string tempName;
    int tempAccNum, tempBal, tempPIN;
    std::cout << "Enter Name: ";
    std::getline(std::cin >> std::ws, tempName);
    temp.setName(tempName);
    std::cout << "Enter PIN: ";
    std::cin >> tempPIN;
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter PIN: ";
        std::cin >> tempPIN;
    }
    temp.setPIN(tempPIN);

    std::cout << "Enter Account Number: ";
    std::cin >> tempAccNum;
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter Account Number: ";
        std::cin >> tempAccNum;
    }
    temp.setAccNum(tempAccNum);

    std::cout << "Enter Initial Balance: ";
    std::cin >> tempBal;
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter Initial Balance: ";
        std::cin >> tempBal;
    }
    if (tempBal <= 0) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter Initial Balance: ";
        std::cin >> tempBal;
    }
    temp.setBal(tempBal);

    bankAccounts.push_back(temp);

    std::cout << "Account \"" << temp.getName() << "\" added.\n";
}

void deleteAccount(vector<bankAcc> &bankAccounts) {
    if (bankAccounts.size() == 0) {
        std::cerr << "Error: No accounts detected.\n";
        return;
    }
    std::cout << "List of Accounts:\n";
    for (int i = 0; i < bankAccounts.size(); i++) {
        std::cout << i << "\t" << bankAccounts[i].getName() << std::endl;
    }
    std::cout << 999 << "\t" << "Exit\n";
    std::cout << "Which account **number** do you wish to delete? ";
    int num;
    std::cin >> num;
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        return;
    }
    if (num == 999) {
        return;
    }
    if (num > bankAccounts.size()) {
        std::cerr << "Error: Number Outside Range.\n";
        return;
    }

    bankAccounts.erase(bankAccounts.begin() + num);

    std::cout << "Bank account deleted.\n";
}

void loginSystem(vector<bankAcc> &bankAccounts) {
    int tempAccNum, tempPIN;

    std::cout << "Enter Account Number: ";
    std::cin >> tempAccNum;
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter Account Number: ";
        std::cin >> tempAccNum;
    }

    std::cout << "Enter PIN: ";
    std::cin >> tempPIN;
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter PIN: ";
        std::cin >> tempPIN;
    }

    // Scan for Acc Num
    int index, indexN, indexP;
    bool ifFound = false;
    bool foundN = false, foundP = false;
    bool matches = false;

    for (int i = 0; i < bankAccounts.size(); i++) {
        if (bankAccounts[i].getAccNum() == tempAccNum) {
            foundN = true;
            indexN = i;
        }
    }

    for (int i = 0; i < bankAccounts.size(); i++) {
        if (bankAccounts[i].getPIN() == tempPIN) {
            foundP = true;
            indexP = i;
        }
    }

    if (foundN && foundP) {
        ifFound = true;
        index = indexN;
    }

    if (indexN == indexP) {
        matches = true;
    }
    else {
        std::cerr << "Error: User not found.\n";
        return;
    }

    // If no account detected
    if (ifFound == false) {
        std::cerr << "Error: User not found.\n";
        return;
    }

    // Main Menu
    bool quit = false;
    do {
        int menuOp;
        std::cout << "--------------------------" << std::endl
                  <<   "Welcome " << bankAccounts[index].getName() << std::endl
                  << "--------------------------" << std::endl
                  << "1. Deposit\n"
                  << "2. Withdraw\n"
                  << "3. Display Balance\n"
                  << "4. Quit\n"
                  << "--------------------------" << std::endl
                  << "Option: ";
        std::cin >> menuOp;
        if (std::cin.fail()) {
            std::cerr << "Error: Invalid Input.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "--------------------------" << std::endl
                      <<   "Welcome " << bankAccounts[index].getName() << std::endl
                      << "--------------------------" << std::endl
                      << "1. Deposit\n"
                      << "2. Withdraw\n"
                      << "3. Display Balance\n"
                      << "4. Quit\n"
                      << "--------------------------" << std::endl
                      << "Option: ";
            std::cin >> menuOp;
        }

        switch(menuOp) {
            case 1: {
                bankAccounts[index].deposit();
                break;
            }
            case 2: {
                bankAccounts[index].withdraw();
                break;
            }
            case 3: {
                bankAccounts[index].displayBal();
                break;
            }
            case 4: {
                quit = true;
                std::cout << "Program is quitting.\n";
                break;
            }
            default: {
                std::cerr << "Error: Invalid Input.\n";
                break;
            }
        }

    } while (quit == false);
}

void saveToFile(vector<bankAcc> bankAccounts) {
    std::ofstream writeFile;

    writeFile.open("bankNameData.txt");

    for (int i = 0; i < bankAccounts.size(); i++) {
        writeFile << bankAccounts[i].getName() << std::endl;
    }

    writeFile.close();

    writeFile.open("bankPINData.txt");

    for (int i = 0; i < bankAccounts.size(); i++) {
        writeFile << bankAccounts[i].getPIN() << std::endl;
    }

    writeFile.close();

    writeFile.open("bankaccNumData.txt");

    for (int i = 0; i < bankAccounts.size(); i++) {
        writeFile << bankAccounts[i].getAccNum() << std::endl;
    }

    writeFile.close();

    writeFile.open("bankaccBalData.txt");

    for (int i = 0; i < bankAccounts.size(); i++) {
        writeFile << bankAccounts[i].getBal() << std::endl;
    }

    std::cout << "Wrote " << bankAccounts.size() << " record(s) to file.\n";
    writeFile.close();
}

void readFromFile(std::vector<bankAcc> &bankAccounts) {
    std::ifstream readFile;

    std::vector<std::string> names;
    std::vector<int> accNums;
    std::vector<int> accPINs;
    std::vector<int> accBals;

    std::string nameTemp;
    int accPINTemp, accNumTemp, accBalTemp;

    readFile.open("bankNameData.txt");

    while (std::getline(readFile, nameTemp)) {
        names.push_back(nameTemp);
    }

    readFile.close();

    readFile.open("bankPINData.txt");

    while (readFile >> accPINTemp) {
        accPINs.push_back(accPINTemp);
    }

    readFile.close();

    readFile.open("bankaccNumData.txt");

    while (readFile >> accNumTemp) {
        accNums.push_back(accNumTemp);
    }

    readFile.close();

    readFile.open("bankaccBalData.txt");

    while (readFile >> accBalTemp) {
        accBals.push_back(accBalTemp);
    }

    // Try creating classes from each vector
    int addedCount = 0;

    for (int i = 0; i < accNums.size(); i++) {
        bankAcc TempAcc;
        TempAcc.setName(names[i]);
        TempAcc.setAccNum(accNums[i]);
        TempAcc.setBal(accBals[i]);
        TempAcc.setPIN(accPINs[i]);
        bankAccounts.push_back(TempAcc);
        addedCount++;
    }

    std::cout << "Read " << addedCount << " record(s) from file.\n";
    readFile.close();
}

// todo
// set PIN limit to 4 digits
// check if account number in account creation matches that of another account
// maybe change login system to user selection (depending if you want to make it ATM-like or not; most likely want to keep it ATM-like)
// maybe make account numbers auto-generated instead of manually inputted
// add error checking to main menu items (4 and 5) if there are no values assigned to member variables like PIN, name, accBal, accNum, etc.
// add setprecision, showpoint, etc. for 2 decimal places
// add $ symbol where necessary (withdraw, deposit, showBal)
// add error checking for negative balance (maybe a warning to the user)
// maybe change PIN from Integer to String (and change entire program accordingly)