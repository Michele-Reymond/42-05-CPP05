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

void Bureaucrat::signForm(Form &form) {
    std::cout << this->_name;
    if (form.getGradeToSign() < this->_grade) {
        std::cout << " couldn't sign " << form.getName() << ": Grade too low" << std::endl;
    } else if (form.getSignStatus() == true)
        std::cout << " couldn't sign " << form.getName() << " : form already signed!" << std::endl;
    else
        std::cout << " signed " << form.getName() << std::endl;
}

void Bureaucrat::checkGrade(std::string message) {
    std::cout << this->_name << " with grade " << this->_grade << ": ";
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << message << std::endl;
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