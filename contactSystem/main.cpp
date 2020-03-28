#include <iostream>
#include <string>
#include <vector>

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
              << "[0] Exit\n"
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
                  << "[0] Exit\n"
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
                     "[0] Exit\n"
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
                         "[0] Exit\n"
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
    std::cout << "Contact found!\n"
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
    std::cout << "Contact found!\n"
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
        std::cout << i << " " << contacts[i].getName() << std::endl;
    }
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
    if (contactIndex > contacts.size() || contactIndex < 0) {
        std::cerr << "Error: Index requested **not** in range of contacts.\n";
        return;
    }
    // Edit
    std::string tempName, tempNum, tempAddress, tempEmail;
    std::cout << "Enter new name: ";
    std::getline(std::cin >> std::ws, tempName);
    std::cout << "Enter new phone number: ";
    std::getline(std::cin >> std::ws, tempNum);
    std::cout << "Enter new address: ";
    std::getline(std::cin >> std::ws, tempAddress);
    std::cout << "Enter new email: ";
    std::getline(std::cin >> std::ws, tempEmail);
    // Change specific contact
    contacts[contactIndex].setName(tempName);
    contacts[contactIndex].setPhoneNum(tempNum);
    contacts[contactIndex].setAddress(tempAddress);
    contacts[contactIndex].setEmail(tempEmail);

    std::cout << "Contact edited.\n";
}

void deleteContact(std::vector<Contact> &contacts) {
    // Check if contacts list is empty
    if (contacts.size() == 0) {
        std::cerr << "\nError: Contacts list is empty.\n";
        return;
    }
    // Search for contact
    for (int i = 0; i < contacts.size(); i++) {
        std::cout << i << " " << contacts[i].getName() << std::endl;
    }
    std::cout << "Select Contact [Index] to Delete: ";
    int contactIndex;
    std::cin >> contactIndex;
    // Error checking for cin
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid Input Detected.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Select Contact [Index] to Delete: ";
        std::cin >> contactIndex;
    }
    // Check if number is outside range
    if (contactIndex > contacts.size() || contactIndex < 0) {
        std::cerr << "Error: Index requested **not** in range of contacts.\n";
        return;
    }
    // Delete
    contacts.erase(contacts.begin() + contactIndex);
    std::cout << "Contact deleted.\n";
}