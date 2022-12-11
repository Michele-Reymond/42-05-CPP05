#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define COLOR_RESET     "\x1b[0m"
#define COLOR           "\x1b[2m"

class Form;

class Intern {

    public:
        Intern();
        Intern(const Intern& instance);
        ~Intern();

        Intern    &operator=(const Intern &instance);

        Form *makeForm(std::string formName, std::string target);

        class NameNotValidExceptions : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "The name of the form isn't valid!";	
                }
        };
};

#endif
