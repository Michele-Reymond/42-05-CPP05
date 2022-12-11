#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define COLOR_RESET     "\x1b[0m"
#define COLOR           "\x1b[2m"

int main() {
    //TEST 1 ShrubberyCreation
    std::cout << COLOR "------ Shrubbery Creation Form -------" << std::endl;
    std::cout << std::endl;
    ShrubberyCreationForm christmas("Christmas Trees", "The garden");
    Bureaucrat grinch(100, "TheGrinch");
    Bureaucrat lutin(150, "Lutin");
    grinch.signForm(christmas); // comment this for an error for unsigned form
    std::cout << COLOR_RESET;
    try {
       grinch.executeForm(christmas);
    //    lutin.executeForm(christmas); // cannot execute
    }
    catch (Form::GradeTooHighException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (Form::NotSignedException & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // //TEST 2 ShrubberyCreation
    // std::cout << COLOR "------ Robotomy Request Form -------" << std::endl;
    // std::cout << std::endl;
    // RobotomyRequestForm robotomy("Robotomy", "The neighbour door");
    // Bureaucrat kevin(40, "Kevin");
    // Bureaucrat marvin(150, "Marvin");
    // kevin.signForm(robotomy); // comment this for an error for unsigned form
    // std::cout << COLOR_RESET;
    // try {
    //    kevin.executeForm(robotomy);
    // //    marvin.executeForm(robotomy); // cannot execute
    // }
    // catch (Form::GradeTooHighException & e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }
    // catch (Form::GradeTooLowException & e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }
    // catch (Form::NotSignedException & e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    // //TEST 3 PresidentialPardonForm
    // std::cout << COLOR "------ Presidential Pardon Form -------" << std::endl;
    // std::cout << std::endl;
    // PresidentialPardonForm pardon("Pardon", "The killer");
    // Bureaucrat Juliette(4, "Juliette");
    // Bureaucrat Sarah(150, "Sarah");
    // Juliette.signForm(pardon); // comment this for an error for unsigned form
    // std::cout << COLOR_RESET;
    // try {
    //    Juliette.executeForm(pardon);
    // //    Sarah.executeForm(christmas); // cannot execute
    // }
    // catch (Form::GradeTooHighException & e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }
    // catch (Form::GradeTooLowException & e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }
    // catch (Form::NotSignedException & e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }


    std::cout << COLOR;
    return 0;
}