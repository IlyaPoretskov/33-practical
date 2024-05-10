#include <iostream>
#include <map>
#include <string>
#include <exception>

class OutOfStock : public std::exception {
public:
    const char* what() const throw() {
        return "Out of stock";
    }
};

class ShoppingCart {
private:

    std::map<std::string, int> items;

public:

    ShoppingCart() = default;

    std::map<std::string, int> GetItems() {
        return items;
    }

    void addItem(const std::string& itemCode, int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("Can't add");
        }
        auto it = items.find(itemCode);
        if (it == items.end()) {
            items[itemCode] = quantity;
        }
        else {
            it->second += quantity;
        }
    }

    void removeItem(const std::string& itemCode, int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("Can't remove");
        }
        auto it = items.find(itemCode);
        if (it != items.end()) {
            if (it->second < quantity) {
                throw OutOfStock();
            }
            it->second -= quantity;
            if (it->second == 0) {
                items.erase(it);
            }
        }
    }

    bool hasItem(const std::string& itemCode) {
        return items.find(itemCode) != items.end();
    }

    int getQuantity(const std::string& itemCode) {
        auto it = items.find(itemCode);
        if (it != items.end()) {
            return it->second;
        }
        return 0;
    }
};

int main() {

    ShoppingCart cart;
    std::string articul;
    int quantity;
    while (true) {
        std::cout << "Add, remove or print: " << std::endl;
        std::string command;
        std::cin >> command;

        if (command == "print") {
            for (const auto& item : cart.GetItems()) {
                std::cout << item.first << ": " << item.second << std::endl;
            }
            continue;
        }

        std::cout << "Input an articul(exit for exit): " << std::endl;
        std::cin >> articul;

        if (articul == "exit") {
            break;
        }
        std::cout << "Input a quantity: " << std::endl;
        std::cin >> quantity;
        if (command == "add") {
            try {
                cart.addItem(articul, quantity);
            }
            catch (const std::exception& e) {
                std::cerr << e.what();
            }
        }
        else if (command == "remove") {
            try {
                cart.removeItem(articul, quantity);
            }
            catch (const std::exception& e) {
                std::cerr << e.what();
            }
        }
        else {
            std::cerr << "Invalid argument" << std::endl;
        }
    }

    system("pause");
    return 0;
}