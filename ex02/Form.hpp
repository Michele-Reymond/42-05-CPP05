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
        virtual ~Form();

        Form    &operator=(const Form &instance);

        virtual     std::string getName() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;
        bool        getSignStatus() const;
        void        setGradeToSign(int gradeToSign);
        void        setGradeToExecute(int gradeToExecute);
        void        setSignStatus(bool status);
        void        beSigned(const Bureaucrat &bureaucrat);
        void        canExecute(const Bureaucrat &bureaucrat) const;

        virtual void execute(Bureaucrat const & executor) const = 0;

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

        class NotSignedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form is not signed";	
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
