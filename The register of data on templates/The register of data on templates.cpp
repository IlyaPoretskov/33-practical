#include "The register of data on templates.h"

int main() {
	std::cout << "Input a register size: " << std::endl;
	int n;
	std::cin >> n;
	Register<std::string, int> reg(n);
	std::cout << "Input the register: " << std::endl;
	try {
		reg.input();
	}
	catch(const std::invalid_argument& x) {
		std::cerr << "Caught exception: " << x.what() << std::endl;
	}
	std::string command;
	for (;;) {
		std::cout << "Input the command(add, remove, print, find, exit): " << std::endl;
		std::cin >> command;
		while (command != "add" && command != "remove" && command != "print" && command != "find" && command != "exit") {
			std::cerr << "Wrong input, try again: " << std::endl;
			std::cin >> command;
		}
		if (command == "add") {
			Pair<std::string, int> pair;
			pair.input();
			reg.add(pair);
		}
		else if (command == "remove") {
			std::cout << "Input the key: " << std::endl;
			std::string key;
			reg.remove(key);
		}
		else if (command == "print")
			reg.print();
		else if (command == "find") {
			std::string key;
			std::cout << "Input the key: " << std::endl;
			std::cin >> key;
			Register<std::string, int> findReg = reg.find(key);
			findReg.print();
		}
		else if (command == "exit") {
			break;
		}
	}
}
