#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public Form {

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string name, std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& instance);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm    &operator=(const RobotomyRequestForm &instance);

        virtual void execute(Bureaucrat const &Bureaucrat) const;
    
    private:
        std::string _target;
};

#endif
