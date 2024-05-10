#include <iostream>
#include <exception>
#include <random>

class Boot : public std::exception {
public:
    const char* what() const noexcept override {
        return "Boot";
    }
};

class Fish : public std::exception {
public:
    const char* what() const noexcept override {
        return "Fish";
    }
};

int play(int field[9], int n) {
    if (field[n] == 1) {
        throw Boot();
    }
    else if (field[n] == 2) {
        throw Fish();
    }
}

void print(std::string field) {
    std::cout << "\t\t\t\t\t\t\t" << field[0] << " " << field[1] << " " << field[2] << std::endl <<
                 "\t\t\t\t\t\t\t" << field[3] << " " << field[4] << " " << field[5] << std::endl <<
                 "\t\t\t\t\t\t\t" << field[6] << " " << field[7] << " " << field[8] << std::endl;
}

int main() {
    std::srand(std::time(nullptr));
    std::cout << "\t\t\t\t\t\t::::Fishing Game::::" << std::endl << std::endl;
    int field[9] = { 0, 0, 0,
                     0, 0, 0,
                     0, 0, 0 };

    field[std::rand() % 9] = 2; //0 - empty, 1 - boot, 2 - fish
    for (int i = 0; i < 3; ++i) {
        for (;;) {
            int randomIndex = std::rand() % 9;
            if (field[randomIndex] == 0) {
                field[randomIndex] = 1;
                break;
            }
        }
    }
    std::cout << "The cells of the field are numbered as follows:" << std::endl;
    print("123456789");
    for (;;) {
        std::cout << "Motion:" << std::endl;
        int n;
        std::cin >> n;
        while (n < 1 || n > 9) {
            std::cerr << "Wrong input, try again" << std::endl;
            std::cin >> n;
        }
        try {
            play(field, n);
            std::cout << "Nothing :(" << std::endl;
        }
        catch(const Boot& x) {
            std::cout << "Caught: " << x.what() << std::endl;
            std::cout << "You lose!" << std::endl;
            break;
        }
        catch(const Fish& y) {
            std::cout << "Caught: " << y.what() << std::endl;
            std::cout << "You won!" << std::endl;
            break;
        }
    }
}
