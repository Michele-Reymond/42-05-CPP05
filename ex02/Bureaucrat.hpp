#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {

    public:
        Bureaucrat();
        Bureaucrat(int grade, std::string name);
        Bureaucrat(const Bureaucrat& instance);
        ~Bureaucrat();

        Bureaucrat    &operator=(const Bureaucrat &instance);

        std::string getName() const;
        int         getGrade() const;
        void        increase();
        void        decrease();
        void        signForm(Form &form);
        void        executeForm(Form const & form);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "The grade is too high";	
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "The grade is too low";	
                }
        };

    private:
        std::string const   _name;
        int                 _grade;

        void    checkGrade(std::string message);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &instance);

#endif
