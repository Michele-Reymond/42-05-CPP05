#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    public:
        Form();
        Form(int gradeToSign, int gradeToExecute, std::string name);
        Form(const Form& instance);
        ~Form();

        Form    &operator=(const Form &instance);

        std::string getName() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;
        bool        getSignStatus() const;
        void        beSigned(const Bureaucrat &bureaucrat) const; 

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade too high";	
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade too low";	
                }
        };

    private:
        std::string const   _name;
        bool                _isSigned;
        int                 _gradeToSign;
        int                 _gradeToExecute;

        void    _checkGrade(std::string message);
};

std::ostream &operator<<(std::ostream &out, Form const &instance);

#endif
