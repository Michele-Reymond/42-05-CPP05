#include <iostream>
#include "Bureaucrat.hpp"

#define COLOR_RESET     "\x1b[0m"
#define COLOR           "\x1b[2m"

int main() {
    std::cout << COLOR "------ BUREAUCRAT CONSTRUCTION OK -------" COLOR_RESET << std::endl;
    std::cout << std::endl;
    //OK
    Bureaucrat Johnson(1, "Johnson");
    Bureaucrat Smith;
    std::cout << Smith;
    Bureaucrat Parker(150, "Parker");
    Parker.increase();

    std::cout << std::endl << std::endl;
    std::cout << COLOR "------ BUREAUCRAT CONSTRUCTION NOT OK -------" COLOR_RESET << std::endl;
    std::cout << std::endl;

    //Pas OK
    // Bureaucrat Roger(180, "Roger");

    // Bureaucrat Roger(150, "Roger");
    // Roger.decrease(); // 151

    Bureaucrat Roger(1, "Roger");
    Roger.increase();


    std::cout << std::endl << std::endl;
    std::cout << COLOR "------ BUREAUCRAT DESTRUCTION -------" COLOR_RESET << std::endl;
    std::cout << std::endl;
    return 0;
}