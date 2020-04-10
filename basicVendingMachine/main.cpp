#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

void vending();

class vendingMachineItem {
    double price;
    std::string name;
public:
    vendingMachineItem() : price(0.0), name("N/A") {}
    vendingMachineItem(std::string n, double p) : name(n), price(p) {}
    void setPrice(double p) {
        this->price = p;
    }
    void setName(std::string n) {
        this->name = n;
    }
    double getPrice() const {
        return this->price;
    }
    std::string getName() const {
        return this->name;
    }
};

void setVectorItems(std::vector<vendingMachineItem> &);

int main() {
    std::vector<vendingMachineItem> items;
    setVectorItems(items);

    std::cout << std::fixed << std::setprecision(2) << std::showpoint;
    double currentLoadedBal = 0;

    std::stringstream ss;
    while (true) {
        std::cout << "\nCurrent balance: $" << currentLoadedBal << std::endl;

        vending();

        std::string command;
        double operand;
        std::cout << "Enter a command: ";
        std::cin >> command >> operand;

        if (command == "add") {
            currentLoadedBal += operand;
        }
        else if (command == "vend") {
            if (currentLoadedBal == 0.0)  {
                std::cerr << "\nError: No Balance Found\n";
                continue;
            }
            else {
                if (currentLoadedBal < items[operand].getPrice()) {
                    std::cerr << "\nError: Insufficient Balance\n";
                    continue;
                }
                else {
                    std::cout << "\nVending: " << items[operand].getName() << std::endl;
                    currentLoadedBal -= items[operand].getPrice();
                }
            }
        }

        std::cout << "\nWant to quit? (Y/N): ";
        char ans;
        std::cin >> ans;
        if (ans == 'Y') {
            break;
        }
        else {
            continue;
        }
    }
    return 0;
}

void setVectorItems(std::vector<vendingMachineItem> &items) {
    items.push_back(vendingMachineItem("Coca Cola", 0.62));
    items.push_back(vendingMachineItem("Sprite", 0.43));
    items.push_back(vendingMachineItem("7-Up", 0.99));
    items.push_back(vendingMachineItem("Mountain Dew", 0.42));
}

void vending() {
    std::cout << "\nVending Machine: \n"
                 "[0] Coca Cola ($0.62)\n"
                 "[1] Sprite ($0.43)\n"
                 "[2] 7-Up ($0.99)\n"
                 "[3] Mountain Dew ($0.42)\n\n";
}