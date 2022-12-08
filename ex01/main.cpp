#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define COLOR_RESET     "\x1b[0m"
#define COLOR           "\x1b[2m"

int main() {
    std::cout << COLOR "------ BUREAUCRAT CAN SIGN FORM -------" COLOR_RESET << std::endl;
    std::cout << std::endl;
    try {
        std::cout << std::endl;
        std::cout << COLOR "- CONSTRUCTOR -" COLOR_RESET << std::endl;
        std::cout << std::endl;
        Bureaucrat roger(1, "Roger");
        Form construction(1, 1, "Construction form 344");
        std::cout << std::endl;
        std::cout << COLOR "- ACTION -" COLOR_RESET << std::endl;
        std::cout << std::endl;
        std::cout << construction;
        roger.signForm(construction);
        construction.beSigned(roger);
        std::cout << std::endl;
        std::cout << COLOR "- DESTRUCTOR -" COLOR_RESET << std::endl;
        std::cout << std::endl;
    }
    catch (Form::GradeTooHighException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl;
    std::cout << COLOR "------ BBUREAUCRAT CANNOT SIGN FORM -------" COLOR_RESET << std::endl;
    std::cout << std::endl;
    try {
        std::cout << std::endl;
        std::cout << COLOR "- CONSTRUCTOR -" COLOR_RESET << std::endl;
        std::cout << std::endl;
        Bureaucrat watson(30, "Watson");
        Form panic(20, 1, "Panic form 125");
        std::cout << std::endl;
        std::cout << COLOR "- ACTION -" COLOR_RESET << std::endl;
        std::cout << std::endl;
        std::cout << panic;
        watson.signForm(panic);
        panic.beSigned(watson);
    }
    catch (Form::GradeTooHighException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}