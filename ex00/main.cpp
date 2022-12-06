#include <iostream>
#include "Bureaucrat.hpp"

#define COLOR_RESET     "\x1b[0m"
#define COLOR           "\x1b[2m"

int main() {
    std::cout << COLOR "------ BUREAUCRAT CONSTRUCTION -------" COLOR_RESET << std::endl;
    std::cout << std::endl;
    Bureaucrat Ted(1, "Ted");
    Bureaucrat Roger(180, "Roger");
    std::cout << std::endl << std::endl;
    std::cout << COLOR "------ BUREAUCRAT DESTRUCTION -------" COLOR_RESET << std::endl;
    std::cout << std::endl;
    return 0;
}