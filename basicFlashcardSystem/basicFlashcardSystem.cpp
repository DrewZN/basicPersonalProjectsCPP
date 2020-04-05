#include <iostream>
#include <string>
#include <vector>

class Flashcard {
	std::string frontSide, backSide;
	bool ifCorrect = false;
public:
	Flashcard(): frontSide("Blank"), backSide("Blank") {}
	void setFrontSide(std::string);
	void setBackSide(std::string);
	void setCorrect(bool);
	std::string getFrontSide() const;
	std::string getBackSide() const;
	bool getCorrect() const;
};

void Flashcard::setFrontSide(std::string fs) {
	frontSide = fs;
}

void Flashcard::setBackSide(std::string bs) {
	backSide = bs;
}

void Flashcard::setCorrect(bool ifC) {
	ifCorrect = ifC;
}

std::string Flashcard::getFrontSide() const {
	return frontSide;
}

std::string Flashcard::getBackSide() const {
	return backSide;
}

bool Flashcard::getCorrect() const {
	return ifCorrect;
}

void mainMenu();
void addFlashCard(std::vector<Flashcard> &);
void editFlashCard(std::vector<Flashcard> &);
void removeFlashCard(std::vector<Flashcard> &);
void viewFlashCards(std::vector<Flashcard> &);
void practiceFlashCards(std::vector<Flashcard>);

int main() {
	std::vector<Flashcard> flashcards;
	bool quit = false;
	do {
		int menuOp;
		mainMenu();
		std::cin >> menuOp;
		while (std::cin.fail()) {
            std::cerr << "\n---------------------\n";
            std::cerr << "Error: Invalid Input.\n";
            std::cerr << "---------------------\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			mainMenu();
			std::cin >> menuOp;
		}
		switch(menuOp) {
			case 1: {
			    std::cout << std::endl;
				addFlashCard(flashcards);
				break;
			}
			case 2: {
                std::cout << std::endl;
				removeFlashCard(flashcards);
				break;
			}
			case 3: {
			    std::cout << std::endl;
			    editFlashCard(flashcards);
			    break;
			}
			case 4: {
                std::cout << std::endl;
				viewFlashCards(flashcards);
				break;
			}
			case 5: {
                std::cout << std::endl;
				practiceFlashCards(flashcards);
				break;
			}
			case 6: {
                std::cout << "\n----------------\n";
                std::cout << "Exiting Program.\n";
                std::cout << "----------------\n";
				quit = true;
				break;
			}
			default: {
                std::cerr << "\n---------------------\n";
				std::cerr << "Error: Unknown Option\n";
                std::cerr << "---------------------\n";
				break;
			}
		}
	} while (quit == false);
}

void mainMenu() {
	std::cout << "\nMain Menu:\n"
		  << "[1] Add a Flashcard\n"
	  	  << "[2] Delete a Flashcard\n"
	  	  << "[3] Edit a Flashcard\n"
		  << "[4] View Flashcards\n"
		  << "[5] Practice Flashcards\n"
		  << "[6] Exit\n"
		  << "Option: ";
}

void addFlashCard(std::vector<Flashcard> &flashcards) {
	Flashcard temp;
	std::string front, back;
	std::cout << "Enter the front side of the flashcard: \n\n";
	std::getline(std::cin >> std::ws, front);
	std::cout << "\nEnter the back side of the flashcard: \n\n";
	std::getline(std::cin >> std::ws, back);

	temp.setFrontSide(front);
	temp.setBackSide(back);

	flashcards.push_back(temp);
	std::cout << "\n------------------\n";
	std::cout << "Flashcard created!\n";
    std::cout << "------------------\n";
}

void editFlashCard(std::vector<Flashcard> &flashcards) {
    if (flashcards.size() <= 0) {
        std::cout << "---------------------------\n";
        std::cerr << "Error: No flashcards saved.\n";
        std::cout << "---------------------------\n";
        return;
    }
    std::cout << "List of Current Flashcards by Front Side: \n";
    for (int i = 0; i < flashcards.size(); i++) {
        std::cout << i << "\t" << flashcards[i].getFrontSide() << std::endl;
    }
    std::cout << -1 << "\t" << "Quit\n";
    int toEdit;
    std::cout << "\nType in Number of Flashcard to Edit: ";
    std::cin >> toEdit;

    while (std::cin.fail()) {
        std::cerr << "\n---------------------\n";
        std::cerr << "Error: Invalid Input.\n";
        std::cerr << "---------------------\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Type in Number of Flashcard to Edit: ";
        std::cin >> toEdit;
    }
    if (toEdit == -1) {
        return;
    }
    while (toEdit < -1 || toEdit > flashcards.size()) {
        std::cerr << "\n----------------------------------\n";
        std::cerr << "Error: Number Inputted is Invalid.\n"
                  << "Please try again.\n";
        std::cerr << "----------------------------------\n\n";
        std::cout << "Type in Number of Flashcard to Edit: ";
        std::cin >> toEdit;
    }
    // Edit Flashcard Menu
    bool quit = false;
    do {
        int detailEdit;
        std::cout << "\n[1] Edit Front Side: " << flashcards[toEdit].getFrontSide() << std::endl;
        std::cout << "[2] Edit Back Side: " << flashcards[toEdit].getBackSide() << std::endl;
        std::cout << "[3] Exit\n"
                     "Option: ";
        std::cin >> detailEdit;

        while (std::cin.fail()) {
            std::cerr << "\n---------------------\n";
            std::cerr << "Error: Invalid Input.\n";
            std::cerr << "---------------------\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "\n[1] Edit Front Side: " << flashcards[toEdit].getFrontSide() << std::endl;
            std::cout << "[2] Edit Back Side: " << flashcards[toEdit].getBackSide() << std::endl;
            std::cout << "[3] Exit\n"
                         "Option: ";
            std::cin >> detailEdit;
        }
        switch(detailEdit) {
            case 1: {
                std::string newFront;
                std::cout << "\nEnter new front side: \n\n";
                std::getline(std::cin >> std::ws, newFront);
                flashcards[toEdit].setFrontSide(newFront);
                std::cout << "\n-----------------\n";
                std::cout << "Front side edited\n";
                std::cout << "-----------------\n";
                break;
            }
            case 2: {
                std::string newBack;
                std::cout << "\nEnter new back side: \n\n";
                std::getline(std::cin >> std::ws, newBack);
                flashcards[toEdit].setBackSide(newBack);
                std::cout << "\n----------------\n";
                std::cout << "Back side edited\n";
                std::cout << "----------------\n";
                break;
            }
            case 3: {
                std::cout << "\n---------------------\n";
                std::cout << "Exiting to Main Menu.\n";
                std::cout << "---------------------\n";
                quit = true;
                break;
            }
            default: {
                std::cerr << "\n----------------------\n";
                std::cerr << "Error: Unknown Option.\n";
                std::cerr << "----------------------\n";
                break;
            }
        }
    } while (quit == false);
}

void removeFlashCard(std::vector<Flashcard> &flashcards) {
	if (flashcards.size() <= 0) {
        std::cerr << "---------------------------\n";
		std::cerr << "Error: No flashcards saved.\n";
        std::cerr << "---------------------------\n";
		return;
	}
	std::cout << "List of Current Flashcards by Front Side: \n";
	for (int i = 0; i < flashcards.size(); i++) {
		std::cout << i << "\t" << flashcards[i].getFrontSide() << std::endl;
	}
	std::cout << -1 << "\t" << "Quit\n";
	int toDelete;
	std::cout << "\nType in Number of Flashcard to Delete: ";
	std::cin >> toDelete;

	while (std::cin.fail()) {
        std::cerr << "\n---------------------\n";
        std::cerr << "Error: Invalid Input.\n";
        std::cerr << "---------------------\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "\nType in Number of Flashcard to Delete: ";
		std::cin >> toDelete;
	}
	if (toDelete == -1) {
	    return;
	}
	while (toDelete < -1 || toDelete > flashcards.size()) {
        std::cerr << "\n----------------------------------\n";
        std::cerr << "Error: Number Inputted is Invalid.\n"
                  << "Please try again.\n";
        std::cerr << "----------------------------------\n\n";
        std::cout << "Type in Number of Flashcard to Delete: ";
		std::cin >> toDelete;
	}

	flashcards.erase(flashcards.begin() + toDelete);
	std::cout << "\n-----------------\n";
	std::cout << "Flashcard deleted\n";
    std::cout << "-----------------\n";
}

void viewFlashCards(std::vector<Flashcard> &flashcards) {
	if (flashcards.size() <= 0) {
        std::cerr << "---------------------------\n";
        std::cerr << "Error: No flashcards saved.\n";
        std::cerr << "---------------------------\n";
		return;
	}
	std::cout << "Front Side: \t\t\t" << "BackSide: \n";
	for (int i = 0; i < flashcards.size(); i++) {
		std::cout << flashcards[i].getFrontSide() << " \t\t\t" << flashcards[i].getBackSide() << std::endl;
	}
	std::cout << std::endl;
}

void practiceFlashCards(std::vector<Flashcard> flashcards) {
	if (flashcards.size() <= 0) {
        std::cerr << "---------------------------\n";
        std::cerr << "Error: No flashcards saved.\n";
        std::cerr << "---------------------------\n";
		return;
	}

	for (int i = 0; i < flashcards.size(); i++) {
		std::string ans;
		std::cout << "What is the back side of \"" << flashcards[i].getFrontSide() << "\"? \n";
		std::getline(std::cin >> std::ws, ans);
		while (flashcards[i].getCorrect() == false) {
            std::cerr << "\n----------------------------\n";
			std::cerr << "Incorrect. Please Try Again.\n";
            std::cerr << "----------------------------\n\n";
            std::cout << "What is the back side of \"" << flashcards[i].getFrontSide() << "\"? \n";
            std::getline(std::cin >> std::ws, ans);
            if (ans == flashcards[i].getBackSide()) {
                flashcards[i].setCorrect(true);
            }
		}
	}
}