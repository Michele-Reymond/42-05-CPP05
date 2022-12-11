#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

#define COLOR_RESET     "\x1b[0m"
#define COLOR           "\x1b[2m"

int main() {
    std::cout << COLOR "------ Intern can create form-------" << std::endl;
    std::cout << std::endl;
    Intern lutin;
    Bureaucrat bigBoss(1, "Madona");
    Form* form1;
    Form* form2;
    try {
    //    form1 = lutin.makeForm("Robotomy request", "Bender");
    //    form1 = lutin.makeForm("Presidential pardon", "Bender");
       form1 = lutin.makeForm("Shrubbery creation", "a lost island");
    }
    catch (Intern::NameNotValidExceptions & e) {
        std::cout << "Error: " << e.what() << std::endl;
        delete(form1);
    }
    std::cout << COLOR_RESET;
    bigBoss.signForm(*form1);
    bigBoss.executeForm(*form1);
    std::cout << COLOR;
    delete(form1);
    std::cout << std::endl << std::endl;
    std::cout << COLOR "------ Intern cannot create form -------" << std::endl;
    std::cout << std::endl;
    try {
    //    form2 = lutin.makeForm("pouette", "Pikachu");
       form2 = lutin.makeForm("robotomy request", "Pikachu");
       delete(form2);
    }
    catch (Intern::NameNotValidExceptions & e) {
        std::cout << COLOR_RESET << "Error: " << e.what() << COLOR << std::endl;
        delete(form2);
    }
    return 0;
}