#include "RobotomyRequestForm.hpp"
# include <ctime>

// ---------Constructor and destructor ------------

RobotomyRequestForm::RobotomyRequestForm() : Form(72, 45, "RobotomyRequestForm 101"), _target("shrubbery") {
    std::cout << "A new \"RobotomyRequestForm 101\" is out" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : 
        Form(72, 45, name),
        _target(target) {
    std::cout << "RobotomyRequestForm \"" << name << "\": is out" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& instance) {
    *this = instance;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructed" << std::endl;
}

// --------- Fonctions ------------

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
    this->canExecute(bureaucrat);
	std::srand(time(NULL));
	if (rand() % 2)
		std::cout << "ra-ta-ta-ta-ra-ta-ta-ta-ra-ta-ta-ta" << std::endl << this->_target << " was well robotomised" << std::endl;
	else
		std::cout << "Oops the robotomisation failed on " << this->_target << std::endl;
}

// --------- Operator overload ------------

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &instance) {
    std::cout << "A RobotomyRequestForm is copied" << std::endl;
    this->setGradeToSign(instance.getGradeToSign());
    this->setGradeToExecute(instance.getGradeToExecute());
    this->setSignStatus(instance.getSignStatus());
    return *this;
}
