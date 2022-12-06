#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

    public:
        Bureaucrat(int grade, std::string name);
        Bureaucrat(const Bureaucrat& instance);
        ~Bureaucrat();

        Bureaucrat    &operator=(const Bureaucrat &instance);

        std::string getName() const;
        int         getGrade() const;
        void        increase();
        void        decrease();

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
        const std::string   _name;
        int                 _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &instance);

#endif
