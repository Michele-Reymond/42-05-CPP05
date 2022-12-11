#include "PresidentialPardonForm.hpp"

// ---------Constructor and destructor ------------

PresidentialPardonForm::PresidentialPardonForm() : Form(25, 5, "PresidentialPardonForm 101"), _target("shrubbery") {
    std::cout << "A new \"PresidentialPardonForm 101\" is out" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) : 
        Form(25, 5, name),
        _target(target) {
    std::cout << "PresidentialPardonForm \"" << name << "\": is out" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& instance) {
    *this = instance;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructed" << std::endl;
}

// --------- Fonctions ------------

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
    this->canExecute(bureaucrat);
	std::cout << this->_target << " was pardoned by Zaphod Beeblebrox!" << std::endl;
}

// --------- Operator overload ------------

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &instance) {
    std::cout << "A PresidentialPardonForm is copied" << std::endl;
    this->setGradeToSign(instance.getGradeToSign());
    this->setGradeToExecute(instance.getGradeToExecute());
    this->setSignStatus(instance.getSignStatus());
    return *this;
}
