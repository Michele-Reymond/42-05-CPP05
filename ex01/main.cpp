#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define COLOR_RESET     "\x1b[0m"
#define COLOR           "\x1b[2m"

int main() {
    //TEST 1 form creation
    std::cout << COLOR "------ Form creation work -------" COLOR_RESET << std::endl;
    std::cout << std::endl;
    try {
        Form good(150, 1, "GOOD form");
    }
    catch (Form::GradeTooHighException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl << std::endl;
    std::cout << COLOR "------ Form creation doesn't work -------" COLOR_RESET << std::endl;
    std::cout << std::endl;
    try {
        Form bad(151, 1, "BAD form");
    }
    catch (Form::GradeTooHighException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // TEST 2 SIGN FORM NOT OK
    // std::cout << COLOR "------ CONSTRUCTION -------" COLOR_RESET << std::endl;
    // std::cout << std::endl;
    // Bureaucrat roger(3, "Roger");
    // Form construction(1, 1, "Construction form 344");
    // std::cout << std::endl << std::endl;
    // std::cout << COLOR "------ TRY TO SIGN -------" COLOR_RESET << std::endl;
    // std::cout << std::endl;
    // roger.signForm(construction);
    // std::cout << construction;
    // std::cout << std::endl << std::endl;
    // std::cout << COLOR "------ DESTRUCTION -------" COLOR_RESET << std::endl;


    // TEST 3 SIGN FORM IS OK
    // std::cout << COLOR "------ CONSTRUCTION -------" COLOR_RESET << std::endl;
    // std::cout << std::endl;
    // Bureaucrat watson(10, "Watson");
    // Form panic(20, 1, "Panic form 125");
    // std::cout << std::endl << std::endl;
    // std::cout << COLOR "------ TRY TO SIGN -------" COLOR_RESET << std::endl;
    // std::cout << std::endl;
    // watson.signForm(panic);
    // std::cout << panic;
    // std::cout << std::endl << std::endl;
    // std::cout << COLOR "------ DESTRUCTION -------" COLOR_RESET << std::endl;



    return 0;
}