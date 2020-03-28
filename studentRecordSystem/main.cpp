#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Student {
    std::string firstName, lastName, course;
    char section;
public:
    void setFirstName(std::string);
    void setLastName(std::string);
    void setCourse(std::string);
    void setSection(char);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getCourse() const;
    char getSection() const;
};

void Student::setFirstName(std::string fn) {
    firstName = fn;
}

void Student::setLastName(std::string ln) {
    lastName = ln;
}

void Student::setCourse(std::string tempCourse) {
    course = tempCourse;
}

void Student::setSection(char tempSection) {
    section = tempSection;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getCourse() const {
    return course;
}

char Student::getSection() const {
    return section;
}

void addRecords(std::vector<Student> &);
void listRecords(std::vector<Student> );
void modifyRecords(std::vector<Student> &);
void deleteRecords(std::vector<Student> &);
void saveToFile(const std::vector<Student>);
void readFromFile(std::vector<Student> &);

int main() {
    std::vector<Student> students;

    bool quit = false;
    do {
        int menuOp;
        std::cout << "Main Menu:\n"
                     "[1] Add Record\n"
                     "[2] List Records\n"
                     "[3] Modify Records\n"
                     "[4] Delete Records\n"
                     "[5] Save to File\n"
                     "[6] Read from File\n"
                     "[7] Exit\n"
                     "Option: ";
        std::cin >> menuOp;
        if (std::cin.fail()) {
            std::cerr << "Error: Invalid Input.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Main Menu:\n"
                         "[1] Add Record\n"
                         "[2] List Records\n"
                         "[3] Modify Records\n"
                         "[4] Delete Records\n"
                         "[5] Save to File\n"
                         "[6] Read from File\n"
                         "[7] Exit\n"
                         "Option: ";
            std::cin >> menuOp;
        }
        switch(menuOp) {
            case 1: {
                addRecords(students);
                break;
            }
            case 2: {
                listRecords(students);
                break;
            }
            case 3: {
                modifyRecords(students);
                break;
            }
            case 4: {
                deleteRecords(students);
                break;
            }
            case 5: {
                saveToFile(students);
                break;
            }
            case 6: {
                readFromFile(students);
                break;
            }
            case 7: {
                quit = true;
                std::cout << "Program exiting.\n";
                break;
            }
            default: {
                std::cerr << "Invalid Input.\n";
                break;
            }
        }
    } while (quit == false);

    return 0;
}

void addRecords(std::vector<Student> &students) {
    std::string fName, lName, course;
    char section;

    std::cout << "Enter First Name: ";
    std::getline(std::cin >> std::ws, fName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin >> std::ws, lName);
    std::cout << "Enter Course: ";
    std::getline(std::cin >> std::ws, course);
    std::cout << "Enter Section: ";
    std::cin >> section;

    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter Section: ";
        std::cin >> section;
    }

    Student tempStudent;
    tempStudent.setFirstName(fName);
    tempStudent.setLastName(lName);
    tempStudent.setCourse(course);
    tempStudent.setSection(section);
    students.push_back(tempStudent);

    std::cout << "Student added!\n";
}

void listRecords(std::vector<Student> students) {
    if (students.size() == 0) {
        std::cerr << "Error: No records detected.\n";
        return;
    }
    std::cout << "=================\n";
    std::cout << "Student Records: \n";
    std::cout << "=================\n";
    for (int i = 0; i < students.size(); i++) {
        std::cout << i+1 << ". " << students[i].getLastName() << ", " << students[i].getFirstName() << "\t" << students[i].getCourse() << "\t" << students[i].getSection() << std::endl;
    }
    std::cout << "=================\n";
}

void modifyRecords(std::vector<Student> &students) {
    if (students.size() == 0) {
        std::cerr << "Error: No records detected.\n";
        return;
    }

    listRecords(students);

    std::cout << "Select a number of the record you want to modify: ";
    int recordModify;
    std::cin >> recordModify;

    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Select a number of the record you want to modify: ";
        std::cin >> recordModify;
    }

    if (recordModify == -1) {
        std::cout << "Exiting to Main Menu.\n";
        return;
    }
    if (recordModify < 0) {
        std::cerr << "Error: Invalid Number (Outside Range)\n";
        return;
    }
    if (recordModify > students.size()) {
        std::cerr << "Error: Invalid Number (Outside Range)\n";
        return;
    }

    // Modify Menu
    bool quit = false;
    do {
        int menuOp;
        std::cout << "=================\n";
        std::cout << "Modify Menu\n";
        std::cout << "=================\n";
        std::cout << "[1] First Name - " << students[recordModify-1].getFirstName() << std::endl
                  << "[2] Last Name - " << students[recordModify-1].getLastName() << std::endl
                  << "[3] Course - " << students[recordModify-1].getCourse() << std::endl
                  << "[4] Section - " << students[recordModify-1].getSection() << std::endl
                  << "[5] Exit to Main Menu\n"
                     "=================\n"
                     "Option: ";
        std::cin >> menuOp;

        if (std::cin.fail()) {
            std::cerr << "Error: Invalid Input.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "=================\n";
            std::cout << "Modify Menu\n";
            std::cout << "=================\n";
            std::cout << "[1] First Name - " << students[recordModify-1].getFirstName() << std::endl
                      << "[2] Last Name - " << students[recordModify-1].getLastName() << std::endl
                      << "[3] Course - " << students[recordModify-1].getCourse() << std::endl
                      << "[4] Section - " << students[recordModify-1].getSection() << std::endl
                      << "[5] Exit to Main Menu\n"
                         "=================\n"
                         "Option: ";
            std::cin >> menuOp;
        }

        switch(menuOp) {
            case 1: {
                std::string tempF;
                std::cout << "Edit First Name: ";
                std::getline(std::cin >> std::ws, tempF);
                students[recordModify-1].setFirstName(tempF);
                std::cout << "First Name Modified!\n";
                break;
            }
            case 2: {
                std::string tempL;
                std::cout << "Edit Last Name: ";
                std::getline(std::cin >> std::ws, tempL);
                students[recordModify-1].setLastName(tempL);
                std::cout << "Last Name Modified!\n";
                break;
            }
            case 3: {
                std::string tempC;
                std::cout << "Edit Course: ";
                std::getline(std::cin >> std::ws, tempC);
                students[recordModify-1].setCourse(tempC);
                std::cout << "Course Modified!\n";
                break;
            }
            case 4: {
                char tempS;
                std::cout << "Edit Section: ";
                std::cin >> tempS;
                students[recordModify-1].setSection(tempS);
                std::cout << "Section Modified!\n";
                break;
            }
            case 5: {
                std::cout << "Exiting to Main Menu.\n";
                quit = true;
                break;
            }
            default: {
                std::cerr << "Error: Invalid Input.\n";
                break;
            }
        }

    } while (quit == false);
}

void deleteRecords(std::vector<Student> &students) {
    if (students.size() == 0) {
        std::cerr << "Error: No records detected.\n";
        return;
    }

    listRecords(students);
    std::cout << -1 << " Exit\n";
    std::cout << "=================\n"
                 "Select Record Index: ";

    int toDelete;
    std::cin >> toDelete;

    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        listRecords(students);
        std::cout << -1 << " Exit\n";
        std::cout << "=================\n"
                     "Select Record Index: ";
        std::cin >> toDelete;
    }

    if (toDelete == -1) {
        std::cout << "Exiting to Main Menu.\n";
        return;
    }
    if (toDelete < 0) {
        std::cerr << "Error: Invalid Number (Outside Range)\n";
        return;
    }
    if (toDelete > students.size()) {
        std::cerr << "Error: Invalid Number (Outside Range)\n";
        return;
    }

    // Delete Record
    students.erase(students.begin() + (toDelete-1));
    std::cout << "Deleted record.\n";
}

void saveToFile(const std::vector<Student> students) {
    if (students.size() == 0) {
        std::cerr << "Warning: Erasing All Files.\n";
    }
    
    std::ofstream writeFirstNames, writeLastNames, writeCourses, writeSections;
    int saveCount = 0;
    
    writeFirstNames.open("firstNamesData.txt");
    writeLastNames.open("lastNamesData.txt");
    writeCourses.open("coursesData.txt");
    writeSections.open("sectionsData.txt");
    
    for (int i = 0; i < students.size(); i++) {
        writeFirstNames << students[i].getFirstName() << std::endl;
        writeLastNames << students[i].getLastName() << std::endl;
        writeCourses << students[i].getCourse() << std::endl;
        writeSections << students[i].getSection() << std::endl;
        ++saveCount;
    }
    
    // Close Files
    writeFirstNames.close();
    writeLastNames.close();
    writeCourses.close();
    writeSections.close();
    
    std::cout << "Saved " << saveCount << " to files.\n";
}

void readFromFile(std::vector<Student> &students) {
    std::ifstream readFirstNames, readLastNames, readCourses, readSections;

    readFirstNames.open("firstNamesData.txt");
    readLastNames.open("lastNamesData.txt");
    readCourses.open("coursesData.txt");
    readSections.open("sectionsData.txt");

    std::string tempFN, tempLN, tempC;
    char tempS;
    int readCounter = 0;

    while ((std::getline(readFirstNames, tempFN)) && (std::getline(readLastNames, tempLN) && (std::getline(readCourses, tempC)) && (readSections >> tempS))) {
        Student tempStudent;
        tempStudent.setFirstName(tempFN);
        tempStudent.setLastName(tempLN);
        tempStudent.setCourse(tempC);
        tempStudent.setSection(tempS);
        students.push_back(tempStudent);
        ++readCounter;
    }

    std::cout << "Read " << readCounter << " records from file.\n";
}