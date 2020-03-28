#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Class and Member Functions
class Contact{
    std::string name;
    std::string phoneNum;
    std::string email;
    std::string address;
public:
    // Setters
    void setName(std::string);
    void setPhoneNum(std::string);
    void setEmail(std::string);
    void setAddress(std::string);
    // Getters
    std::string getName() const;
    std::string getPhoneNum() const;
    std::string getEmail() const;
    std::string getAddress() const;
};

void Contact::setName(std::string tempName) {
    name = tempName;
}

void Contact::setPhoneNum(std::string tempPhoneNum) {
    phoneNum = tempPhoneNum;
}

void Contact::setEmail(std::string tempEmail) {
    email = tempEmail;
}

void Contact::setAddress(std::string tempAddress) {
    address = tempAddress;
}

std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhoneNum() const {
    return phoneNum;
}

std::string Contact::getEmail() const {
    return email;
}

std::string Contact::getAddress() const {
    return address;
}

// Function Prototypes
void mainMenu(int&);
void createNewContact(std::vector<Contact> &);
void listAllContacts(std::vector<Contact> &);
void searchForContact(const std::vector<Contact>);
void editContact(std::vector<Contact> &);
void deleteContact(std::vector<Contact> &);
void searchContactName(const std::vector<Contact>);
void searchContactNum(const std::vector<Contact>);
void saveToFile(const std::vector<Contact>);
void readFromFile(std::vector<Contact> &);

int main() {
    std::vector<Contact> contacts;
    int menuOp;
    bool quit = false;
    do {
        mainMenu(menuOp);
        switch(menuOp) {
            case 1: {
                createNewContact(contacts);
                break;
            }
            case 2: {
                listAllContacts(contacts);
                break;
            }
            case 3: {
                searchForContact(contacts);
                break;
            }
            case 4: {
                editContact(contacts);
                break;
            }
            case 5: {
                deleteContact(contacts);
                break;
            }
            case 6: {
                saveToFile(contacts);
                break;
            }
            case 7: {
                readFromFile(contacts);
                break;
            }
            case 0: {
                std::cerr << "Program is exiting.\n";
                quit = true;
                break;
            }
            default: {
                std::cerr << "Error: Unknown Input.\n";
                break;
            }
        }
    } while (quit == false);

    return 0;
}

void mainMenu(int &menuOp) {
    std::cout << "=====================\n"
              << "Main Menu:\n"
              << "=====================\n"
              << "[1] Add new contact\n"
              << "[2] List all contacts\n"
              << "[3] Search for contact\n"
              << "[4] Edit a contact\n"
              << "[5] Delete a contact\n"
              << "[6] Save to File\n"
              << "[7] Read from File\n"
              << "[0] Exit Program\n"
              << "=====================\n"
              << "Enter choice: ";
    std::cin >> menuOp;
    // Error checking
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Option.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "=====================\n"
                  << "Main Menu:\n"
                  << "=====================\n"
                  << "[1] Add new contact\n"
                  << "[2] List all contacts\n"
                  << "[3] Search for contact\n"
                  << "[4] Edit a contact\n"
                  << "[5] Delete a contact\n"
                  << "[6] Save to File\n"
                  << "[7] Read from File\n"
                  << "[0] Exit Program\n"
                  << "=====================\n"
                  << "Enter choice: ";
        std::cin >> menuOp;
    }
}

void createNewContact(std::vector<Contact> &contacts) {
    // Prompt for information
    Contact temp;
    std::string name, phoneNum, email, address;
    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin >> std::ws, phoneNum);
    std::cout << "Enter email: ";
    std::getline(std::cin >> std::ws, email);
    std::cout << "Enter address: ";
    std::getline(std::cin >> std::ws, address);

    temp.setName(name);
    temp.setPhoneNum(phoneNum);
    temp.setEmail(email);
    temp.setAddress(address);

    contacts.push_back(temp);

    std::cout << "Added contact \"" << temp.getName() << "\"\n";
}

void listAllContacts(std::vector<Contact> &contacts) {
    // Check if contacts list is empty
    if (contacts.size() == 0) {
        std::cerr << "\nError: Contacts list is empty.\n";
        return;
    }
    // List all contacts
    std::cout << "=====================\n";
    std::cout << "Contacts List:\n";
    std::cout << "=====================\n";
    for (int i = 0; i < contacts.size(); i++) {
        std::cout << i+1 << ".\t" << contacts[i].getName() << "\t" << contacts[i].getPhoneNum() << "\t" << contacts[i].getEmail() << "\t" << contacts[i].getAddress() << std::endl;
    }
    std::cout << "=====================\n";
}

void searchForContact(const std::vector<Contact> contacts) {
    // Check if contacts list is empty
    if (contacts.size() == 0) {
        std::cerr << "\nError: Contacts list is empty.\n";
        return;
    }
    // Menu for Name or Number
    bool quit = false;
    do {
        std::cout << "===============\n"
                     "Search Menu:\n"
                     "===============\n"
                     "[1] Search using name\n"
                     "[2] Search using number\n"
                     "[0] Exit to Main Menu\n"
                     "===============\n"
                     "Option: ";
        int searchMenuOp;
        std::cin >> searchMenuOp;
        // Error checking
        if (std::cin.fail()) {
            std::cerr << "Error: Invalid Option.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "===============\n"
                         "Search Menu:\n"
                         "===============\n"
                         "[1] Search using name\n"
                         "[2] Search using number\n"
                         "[0] Exit to Main Menu\n"
                         "===============\n"
                         "Option: ";
            std::cin >> searchMenuOp;
        }
        switch(searchMenuOp) {
            case 1: {
                searchContactName(contacts);
                break;
            }
            case 2: {
                searchContactNum(contacts);
                break;
            }
            case 0: {
                std::cout << "Exiting to Main Menu.\n";
                quit = true;
                break;
            }
            default: {
                std::cerr << "Error: Invalid Option.\n";
                break;
            }
        }
    } while (quit == false);
}

void searchContactName(const std::vector<Contact> contacts) {
    // Check if contacts list is empty
    if (contacts.size() == 0) {
        std::cerr << "\nError: Contacts list is empty.\n";
        return;
    }
    // Search for contact using name
    bool ifFoundN = false;
    // Ask for name to search
    std::string tempName;
    int indexFoundN;
    std::cout << "Enter name to search: ";
    std::getline(std::cin >> std::ws, tempName);
    // Go through contact vector
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getName() == tempName) {
            ifFoundN = true;
            indexFoundN = i;
        }
    }
    // Check if contact was found at all
    if (ifFoundN == false) {
        std::cerr << "Error: Contact Search Using Name: Unsuccessful.\n";
        return;
    }
    // Display Contact Info
    std::cout << "===============\n"
                 "Contact found!\n"
                 "===============\n";
    std::cout << contacts[indexFoundN].getName() << "\t" << contacts[indexFoundN].getPhoneNum() << "\t" << contacts[indexFoundN].getEmail() << "\t" << contacts[indexFoundN].getAddress() << std::endl;
}

void searchContactNum(const std::vector<Contact> contacts) {
    // Check if contacts list is empty
    if (contacts.size() == 0) {
        std::cerr << "\nError: Contacts list is empty.\n";
        return;
    }
    // Search for contact using phone number
    bool ifFoundP = false;
    // Ask for phone number to search
    std::string tempNum;
    int indexFoundP;
    std::cout << "Enter phone number to search: ";
    std::getline(std::cin >> std::ws, tempNum);
    // Go through contact vector
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getPhoneNum() == tempNum) {
            ifFoundP = true;
            indexFoundP = i;
        }
    }
    // Check if contact was found at all
    if (ifFoundP == false) {
        std::cerr << "Error: Contact Search Using Phone Number: Unsuccessful.\n";
        return;
    }
    // Display Contact Info
    std::cout << "===============\n"
                 "Contact found!\n"
                 "===============\n";
    std::cout << contacts[indexFoundP].getName() << "\t" << contacts[indexFoundP].getPhoneNum() << "\t" << contacts[indexFoundP].getEmail() << "\t" << contacts[indexFoundP].getAddress() << std::endl;
}

void editContact(std::vector<Contact> &contacts) {
    // Check if contacts list is empty
    if (contacts.size() == 0) {
        std::cerr << "\nError: Contacts list is empty.\n";
        return;
    }
    // Search for contact
    for (int i = 0; i < contacts.size(); i++) {
        std::cout << i+1 << "\t" << contacts[i].getName() << std::endl;
    }
    std::cout << -1 << " " << "Exit\n";
    std::cout << "Select Contact [Index] to Edit: ";
    int contactIndex;
    std::cin >> contactIndex;
    // Error checking for cin
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input Detected.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Select Contact [Index] to Edit: ";
        std::cin >> contactIndex;
    }
    // Check if number is outside range
    if (contactIndex > contacts.size() || contactIndex <= 0) {
        std::cerr << "Error: Index requested not in range of contacts.\n";
        return;
    }
    bool quit = false;
    do {
        // Display Individual Contact Info and Ask for Detail to Change
        int detailToChange;
        std::cout << "=====================================\n";
        std::cout << "[1] Name: \t" << contacts[contactIndex].getName() << std::endl
                  << "[2] Phone Number: \t" << contacts[contactIndex].getPhoneNum() << std::endl
                  << "[3] Email: \t" << contacts[contactIndex].getEmail() << std::endl
                  << "[4] Address: \t" << contacts[contactIndex].getAddress() << std::endl
                  << "[0] Exit to Main Menu\n";
        std::cout << "=====================================\n";
        std::cout << "Which detail do you want to change? ";
        std::cin >> detailToChange;
        // Error checking for cin
        if (std::cin.fail()) {
            std::cerr << "Error: Invalid Input Detected.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "=====================================\n";
            std::cout << "[1] Name: \t" << contacts[contactIndex].getName() << std::endl
                      << "[2] Phone Number: \t" << contacts[contactIndex].getPhoneNum() << std::endl
                      << "[3] Email: \t" << contacts[contactIndex].getEmail() << std::endl
                      << "[4] Address: \t" << contacts[contactIndex].getAddress() << std::endl
                      << "[0] Exit to Main Menu\n";
            std::cout << "=====================================\n";
            std::cout << "Which detail do you want to change? ";
            std::cin >> detailToChange;
        }
        // Switch Menu for Detail to Change
        switch(detailToChange) {
            case 1: {
                std::string tempName;
                std::cout << "Change name: ";
                std::getline(std::cin >> std::ws, tempName);
                contacts[contactIndex].setName(tempName);
                std::cout << "Name changed.\n";
                break;
            }
            case 2: {
                std::string tempNum;
                std::cout << "Change phone number: ";
                std::getline(std::cin >> std::ws, tempNum);
                contacts[contactIndex].setPhoneNum(tempNum);
                std::cout << "Phone number changed.\n";
                break;
            }
            case 3: {
                std::string tempEmail;
                std::cout << "Change email: ";
                std::getline(std::cin >> std::ws, tempEmail);
                contacts[contactIndex].setEmail(tempEmail);
                std::cout << "Email changed.\n";
                break;
            }
            case 4: {
                std::string tempAddress;
                std::cout << "Change address: ";
                std::getline(std::cin >> std::ws, tempAddress);
                contacts[contactIndex].setAddress(tempAddress);
                std::cout << "Address changed.\n";
                break;
            }
            case 0: {
                quit = true;
                break;
            }
            default: {
                std::cerr << "Error: Unknown Input.\n";
                break;
            }
        }
    } while (quit == false);
    std::cout << "Exiting to Main Menu.\n";
}

void deleteContact(std::vector<Contact> &contacts) {
    // Check if contacts list is empty
    if (contacts.size() == 0) {
        std::cerr << "\nError: Contacts list is empty.\n";
        return;
    }
    // Search for contact
    for (int i = 0; i < contacts.size(); i++) {
        std::cout << i+1 << "\t" << contacts[i].getName() << std::endl;
    }
    std::cout << -1 << " " << "Exit\n";
    std::cout << "Select Contact [Index] to Delete: ";
    int contactIndex;
    std::cin >> contactIndex;
    // Error checking for cin
    if (std::cin.fail()) {
        std::cerr << "\nError: Invalid Input Detected.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Select Contact [Index] to Delete: ";
        std::cin >> contactIndex;
    }
    // Check if number is outside range
    if (contactIndex > contacts.size() || contactIndex <= 0) {
        std::cerr << "\nError: Index requested not in range of contacts.\n";
        return;
    }
    // Delete
    contacts.erase(contacts.begin() + (contactIndex-1));
    std::cout << "Contact deleted.\n";
}

void saveToFile(const std::vector<Contact> contacts) {
    // If empty vector
    if (contacts.size() == 0) {
        std::cerr << "Erasing Data Files.\n";
    }

    // Open files to write to
    std::ofstream writeNames, writeAddresses, writeNumbers, writeEmails;

    writeNames.open("namesData.txt");
    writeAddresses.open("addressData.txt");
    writeNumbers.open("numbersData.txt");
    writeEmails.open("emailsData.txt");

    // Write to file
    for (int i = 0; i < contacts.size(); i++) {
        writeNames << contacts[i].getName() << std::endl;
        writeNumbers << contacts[i].getPhoneNum() << std::endl;
        writeEmails << contacts[i].getEmail() << std::endl;
        writeAddresses << contacts[i].getAddress() << std::endl;
    }

    std::cout << contacts.size() << " contacts saved to file.\n";

    // Close files
    writeNames.close();
    writeAddresses.close();
    writeNumbers.close();
    writeEmails.close();
}

void readFromFile(std::vector<Contact> &contacts) {
    // Open files to read from
    std::ifstream readNames, readAddresses, readNumbers, readEmails;

    readNames.open("namesData.txt");
    readAddresses.open("addressData.txt");
    readNumbers.open("numbersData.txt");
    readEmails.open("emailsData.txt");

    // Sync from file
    int contactsReadCount = 0;
    std::string tempName, tempNum, tempEmail, tempAddress;

    while ((std::getline(readNames, tempName)) && (readNumbers >> tempNum) && (std::getline(readEmails, tempEmail)) && (std::getline(readAddresses, tempAddress))) {
        Contact tempContact;
        tempContact.setName(tempName);
        tempContact.setPhoneNum(tempNum);
        tempContact.setEmail(tempEmail);
        tempContact.setAddress(tempAddress);
        contacts.push_back(tempContact);
        ++contactsReadCount;
    }

    if (contactsReadCount == 0) {
        std::cerr << "Error: No Contacts Read From File\n";
        return;
    }

    std::cout << "Read " << contactsReadCount << " contacts from file.\n";

    // Close files
    readNames.close();
    readAddresses.close();
    readNumbers.close();
    readEmails.close();
}

/* todo
 * improve menu item display format (basically add a bunch of '=')
 * fix error with out-of-range values for 'edit contact' and 'delete contact'
 * improve error message formatting (maybe unnecessary newlines at beginning of messages)
 * */