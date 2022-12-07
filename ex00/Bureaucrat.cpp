#include "Bureaucrat.hpp"

// ---------Constructor and destructor ------------

Bureaucrat::Bureaucrat() : _grade(150), _name("Smith") {
    std::cout << "A new Smith work in the firm" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _grade(grade), _name(name) {
    checkGrade("work now in the firm!");
}

Bureaucrat::Bureaucrat(const Bureaucrat& instance) : _name(instance._name) {
    this->_grade = instance._grade;
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
    this->_grade--;
    checkGrade("The grade increased");
}

void Bureaucrat::decrease() {
    this->_grade++;
    checkGrade("The grade decreased");
}

void Bureaucrat::checkGrade(std::string message) {
    try {
        if (this->_grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (this->_grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            std::cout << this->_name << " with grade " << this->_grade << ": " << message << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException & e) {
        std::cout << "Error for " << this->_name << ": " << e.what() <<std::endl;
        exit(1);
    }
    catch (Bureaucrat::GradeTooLowException & e) {
        std::cout << "Error for " << this->_name << ": " << e.what() <<std::endl;
        exit(1);
    }
}

// --------- Operator overload ------------

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &instance) {
    std::cout << "A Bureaucrat is copied" << std::endl;
    this->_grade = instance._grade;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &instance)
{
	out << instance.getName() << ", bureaucrat grade " << instance.getGrade() << std::endl;
	return (out);
}