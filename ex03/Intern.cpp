#include "Intern.hpp"

// ---------Constructor and destructor ------------

Intern::Intern(){
    std::cout << "A new Intern work in the firm" << std::endl;
}

Intern::Intern(const Intern& instance) {
   *this = instance;
}

Intern::~Intern() {
    std::cout << "An intern is fired" << std::endl;
}

// --------- Fonctions ------------

Form *Intern::makeForm(std::string formName, std::string target) {
    std::string	formsName[3] = {"Shrubbery creation", "Robotomy request", "Presidential pardon"};
    Form *forms[3] = {
            new ShrubberyCreationForm(formName, target),
			new RobotomyRequestForm(formName, target),
			new PresidentialPardonForm(formName, target)
    };
    for (int i = 0; i < 3; i++) {
		if (formName == formsName[i]) {
			std::cout << COLOR_RESET << "An intern creates \"" << formName << "\" for " << target << COLOR << std::endl;
            for (int j = 0; j < 3; j++) {
                if (j != i)
                    delete(forms[j]);
            }
			return (forms[i]);
		} else {
            delete forms[i];
        }
	}
    throw Intern::NameNotValidExceptions();
}

// --------- Operator overload ------------

Intern &Intern::operator=(const Intern &instance) {
    std::cout << "A Intern is copied" << std::endl;
    return *this;
}
