#include <iostream>
#include "Bureaucrat.hpp"

#define COLOR_RESET     "\x1b[0m"
#define COLOR           "\x1b[2m"

int main() {
    std::cout << COLOR "------ BUREAUCRAT OK -------" COLOR_RESET << std::endl;
    std::cout << std::endl;

    try {
        Bureaucrat roger(1, "Roger");
        Bureaucrat parker(150, "Parker");
        Bureaucrat smith;
        std::cout << smith;
    }
    catch (Bureaucrat::GradeTooHighException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl;
    std::cout << COLOR "------ BUREAUCRAT NOT OK -------" COLOR_RESET << std::endl;
    std::cout << std::endl;
    try {
        Bureaucrat simson(151, "Simson");
    }
    catch (Bureaucrat::GradeTooHighException & e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException & e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
    try {
        Bureaucrat brandon(150, "Brandon");
        brandon.decrease();
    }
    catch (Bureaucrat::GradeTooHighException & e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException & e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
    try {
        Bureaucrat madison(1, "Madison");
        madison.increase();
    }
    catch (Bureaucrat::GradeTooHighException & e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException & e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
    return 0;
}