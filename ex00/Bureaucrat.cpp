#include "Bureaucrat.hpp"

// ---------Constructor and destructor ------------

Bureaucrat::Bureaucrat(int grade, std::string name) : _grade(grade), _name(name) {
    try {
        if (!(grade > 0 && grade < 151))
            throw Bureaucrat::GradeTooHighException();
        else
            std::cout << this->_name << " with grade " << this->_grade << " is new to the firm" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException & e) {
        std::cout << "Error for " << this->_name << ": " << e.what() <<std::endl;
        exit(1);
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& instance) {
    *this = instance;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << this->_name << " is fired" << std::endl;
}

// --------- Fonctions ------------

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::increase() {
    this->_grade++;
}

void Bureaucrat::decrease() {
    this->_grade--;
}

// --------- Operator overload ------------

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &instance) {
    std::cout << "A Bureaucrat is copied" << std::endl;
    this->_grade = instance._grade;
    // this->_name = instance._name;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &instance)
{
	out << instance.getName() << " , bureaucrat grade " << instance.getGrade() << std::endl;
	return (out);
}