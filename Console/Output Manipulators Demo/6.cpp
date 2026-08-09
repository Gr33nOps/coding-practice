#include <iostream>
#include <iomanip> // For manipulators like std::setw, std::setprecision, etc.


int main() {
    // Using std::cout to demonstrate various manipulators

    // 1. std::endl and std::flush
    std::cout << "Demonstrating manipulators:" << std::endl;
    std::cout << "This line ends with std::endl and flushes the buffer." << std::flush;

    // 2. std::setw
    std::cout << "\n\nUsing std::setw to set field width:" << std::endl;
    std::cout << std::setw(10) << "Number" << std::setw(15) << "Description" << std::endl;
    std::cout << std::setw(10) << 1 << std::setw(15) << "First Item" << std::endl;
    std::cout << std::setw(10) << 2 << std::setw(15) << "Second Item" << std::endl;

    // 3. std::setprecision and std::fixed
    std::cout << "\nUsing std::setprecision and std::fixed for floating-point numbers:" << std::endl;
    double pi = 3.14159265358979;
    std::cout << "Default precision: " << pi << std::endl;
    std::cout << "Fixed precision (2 digits): " << std::fixed << std::setprecision(2) << pi << std::endl;
    std::cout << "Fixed precision (5 digits): " << std::fixed << std::setprecision(5) << pi << std::endl;

    // 4. std::scientific
    std::cout << "\nUsing std::scientific notation:" << std::endl;
    std::cout << "Scientific notation: " << std::scientific << pi << std::endl;

    // 5. std::hex, std::oct, std::dec
    int number = 255;
    std::cout << "\nNumber in different bases:" << std::endl;
    std::cout << "Hexadecimal: " << std::hex << number << std::endl;
    std::cout << "Octal: " << std::oct << number << std::endl;
    std::cout << "Decimal: " << std::dec << number << std::endl;

    // 6. std::left, std::right, std::internal
    std::cout << "\nUsing std::left, std::right, and std::internal for alignment:" << std::endl;
    std::cout << std::left << std::setw(15) << "Left Aligned" << std::endl;
    std::cout << std::right << std::setw(15) << "Right Aligned" << std::endl;
    std::cout << std::internal << std::setw(15) << -12345 << std::endl; // Internal alignment is more relevant for numbers

    return 0;
}