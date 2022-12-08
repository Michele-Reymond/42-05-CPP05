#include "Form.hpp"

// ---------Constructor and destructor ------------

Form::Form() : 
        _gradeToSign(150),
        _gradeToExecute(150),
        _name("Form 101"),
        _isSigned(false) {
    std::cout << "A new \"Form 101\" is out" << std::endl;
}

Form::Form(int gradeToSign, int gradeToExecute, std::string name) : 
        _gradeToSign(gradeToSign),
        _gradeToExecute(gradeToExecute),
        _name(name),
        _isSigned(false) {
    _checkGrade("is created!");
}

Form::Form(const Form& instance) : _name(instance._name) {
    *this = instance;
}

Form::~Form() {
    std::cout << "Form \"" << this->_name << "\" is destructed" << std::endl;
}

// --------- Fonctions ------------

std::string Form::getName() const {
    return this->_name;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

bool Form::getSignStatus() const {
    return this->_isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat) const{
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw Form::GradeTooLowException();
    }
}

void Form::_checkGrade(std::string message) {
    std::cout << "Form \"" << this->_name << "\": ";
    if (this->_gradeToSign < 1) {
        std::cout << "Grade to sign: ";
        throw Form::GradeTooHighException();
    }
    else if (this->_gradeToExecute < 1) {
        std::cout << "Grade to execute: ";
        throw Form::GradeTooHighException();
    }
    else if (this->_gradeToSign > 150) {
        std::cout << "Grade to sign: ";
        throw Form::GradeTooLowException();
    }
    else if (this->_gradeToExecute > 150) {
        std::cout << "Grade to execute: ";
        throw Form::GradeTooLowException();
    }
    else
        std::cout << message << std::endl;
}

// --------- Operator overload ------------

Form &Form::operator=(const Form &instance) {
    std::cout << "A Form is copied" << std::endl;
    this->_gradeToSign = instance._gradeToSign;
    this->_gradeToExecute = instance._gradeToExecute;
    this->_isSigned = instance._isSigned;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &instance)
{
	out << instance.getName() << ": grade to sign (" << instance.getGradeToSign()
        << "), grade to execute (" << instance.getGradeToExecute() << ") ";
    if (instance.getSignStatus())
        out << ", this form is signed" << std::endl;
    else
        out << ", this form isn't signed" << std::endl;
	return (out);
}