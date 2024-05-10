#include <iostream>
#include <exception>

template <typename t>
void input(t array[8]) {
    for (int i = 0; i < 8; ++i)
        std::cin >> array[i];
}

template <typename t>
t armean(t array[8]) {
    double armean = 0.0f;
    for (int i = 0; i < 8; i++)
        armean += (double)array[i];
    return armean / 8.0f;
}

int main() {
    int array[8];
    std::cout << "Fill the array (8):" << std::endl;
    input(array);
    std::cout << armean(array) << std::endl;
    system("pause");
    return 0;
}
