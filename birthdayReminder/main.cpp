#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>

struct Birthday {
    std::string name;
    int month, day, year;
    Birthday();
    Birthday(std::string n, int m, int d, int y);
};

Birthday::Birthday() {
    this->name = "John Doe";
    this->month = 1;
    this->day = 1;
    this->year = 1900;
}

Birthday::Birthday(std::string n, int m, int d, int y) {
    this->name = n;
    this->month = m;
    this->day = d;
    this->year = y;
}

// Function Prototypes
void loadFile(std::vector<Birthday> &b);
void mainMenu();
void addBirthday(std::vector<Birthday> &b);
void whoseBirthdayToday(const std::vector<Birthday> &b, const std::tm *ts);
void listAllBirthdays(const std::vector<Birthday> &b);
void save(const std::vector<Birthday> &b);

int main() {
    // Set Current Date
    std::time_t tp = std::time(nullptr);

    std::tm *ts = std::localtime(&tp);

    // Create Birthday Vector
    std::vector<Birthday> birthdays;

    // Load File Contents Into Vector
    loadFile(birthdays);

    // Main Menu
    bool quit = false;
    while (quit == false) {
        mainMenu();

        int menuOption;
        std::cin >> menuOption;

        // Error Checking
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cerr << "Error: Invalid Input.\n";
            mainMenu();
            std::cin >> menuOption;
        }

        while (menuOption > 5 || menuOption < 1) {
            std::cerr << "Error: Invalid Menu Option.\n";
            mainMenu();
            std::cin >> menuOption;
        }

        switch(menuOption) {
            case 1: {
                std::cout << "----------------------\n";
                addBirthday(birthdays);
                break;
            }
            case 2: {
                std::cout << "----------------------\n";
                whoseBirthdayToday(birthdays, ts);
                break;
            }
            case 3: {
                std::cout << "----------------------\n";
                listAllBirthdays(birthdays);
                break;
            }
            case 4: {
                std::cout << "----------------------\n";
                save(birthdays);
                break;
            }
            case 5: {
                std::cout << "----------------------\n";
                quit = true;
                std::cout << "Exiting Program.\n";
                break;
            }
        }
    }

    return 0;
}

// Function Definitions

void loadFile(std::vector<Birthday> &b) {
    // Read From File
    std::string tempN, tempWholeDate;
    int tempM, tempD, tempY;

    std::ifstream readFile("birthdays.txt");

    while (std::getline(readFile, tempN, '\n') && (std::getline(readFile, tempWholeDate, '\n'))) {
        // Split Date Into Individual Elements
        std::stringstream ss(tempWholeDate);
        std::string segment;
        std::vector<std::string> seglist;
        while (std::getline(ss, segment, '/')) {
            seglist.push_back(segment);
        }
        std::vector<int> elements;
        for (const std::string e : seglist) {
            elements.push_back(std::stoi(e));
        }
        // Combine Everything Into A Temp Birthday Object
        tempM = elements.at(0);
        tempD = elements.at(1);
        tempY = elements.at(2);
        Birthday temp (tempN, tempM, tempD, tempY);
        b.push_back(temp);
    }
    // Close File
    readFile.close();
}

void mainMenu() {
    // Main Menu
    std::cout << "----------------------\n"
              << "Main Menu:\n"
              << "----------------------\n"
              << "[1] Add Birthday\n"
              << "[2] Whose Birthday Is It Today?\n"
              << "[3] List All Birthdays\n"
              << "[4] Save\n"
              << "[5] Exit\n"
              << "----------------------\n"
              << "Enter a menu option: ";
}

void addBirthday(std::vector<Birthday> &b) {
    // Add Birthday
    std::string tempN;
    int tempM, tempD, tempY;
    // Enter Name
    std::cout << "Enter Name: ";
    std::getline(std::cin >> std::ws, tempN);
    // Enter Month
    std::cout << "Enter Month: ";
    std::cin >> tempM;
    // Error Checking (Month)
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cerr << "Error: Invalid Input.\n";
        std::cout << "Enter Month: ";
        std::cin >> tempM;
    }
    while (tempM < 1 || tempM > 12) {
        std::cerr << "Error: Invalid Month.\n";
        std::cout << "Enter Month: ";
        std::cin >> tempM;
    }
    // Enter Day
    std::cout << "Enter Day: ";
    std::cin >> tempD;
    // Error Checking (Day)
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cerr << "Error: Invalid Input.\n";
        std::cout << "Enter Day: ";
        std::cin >> tempD;
    }
    while (tempD < 1 || tempD > 31) {
        std::cerr << "Error: Invalid Day.\n";
        std::cout << "Enter Day: ";
        std::cin >> tempD;
    }
    // Enter Year
    std::cout << "Enter Year: ";
    std::cin >> tempY;
    // Error Checking (Day)
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cerr << "Error: Invalid Input.\n";
        std::cout << "Enter Year: ";
        std::cin >> tempY;
    }
    // Create Temporary Birthday Object
    Birthday temp (tempN, tempM, tempD, tempY);
    // Add Temporary Object to Vector
    b.push_back(temp);
}

void whoseBirthdayToday(const std::vector<Birthday> &b, const std::tm *ts) {
    // Check if Birthdays Vector is Empty
    if (b.size() == 0) {
        std::cerr << "Error: No Birthdays Found.\nPlease Add At Least One.\n";
        return;
    }
    // Check for Birthdays Today
    int birthdayCount = 1;
    std::cout << "List of Birthdays Today: \n";
    for (const Birthday &i : b) {
        if (i.month == (ts->tm_mon+1) && i.day == ts->tm_mday) {
            std::cout << "----------------------\n"
                      << "Birthday #" << birthdayCount++ << ":\t" << i.name << "\n"
                      << "----------------------\n";
        }
    }
}

void listAllBirthdays(const std::vector<Birthday> &b) {
    // Check if Birthdays Vector is Empty
    if (b.size() == 0) {
        std::cerr << "Error: No Birthdays Found.\nPlease Add At Least One.\n";
        return;
    }
    // List All Birthdays
    int birthdayCount = 1;
    for (const Birthday &i : b) {
        std::cout << "----------------------\n"
                  << "Birthday #" << birthdayCount++ << ":\t" << i.name << "\n"
                  << "Month: " << i.month << "\n"
                  << "Day: " << i.day << "\n"
                  << "Year: " << i.year << "\n"
                  << "----------------------\n";
    }
}

void save(const std::vector<Birthday> &b) {
    // Save to a file and exit
    std::ofstream writeFile("birthdays.txt");
    for (int i = 0; i < b.size(); i++) {
        writeFile << b.at(i).name << std::endl;
        writeFile << b.at(i).month << "/" << b.at(i).day << "/" << b.at(i).year << std::endl;
    }
    // Close file
    writeFile.close();
}