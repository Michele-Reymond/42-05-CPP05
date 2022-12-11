#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form {

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string name, std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& instance);
        virtual ~PresidentialPardonForm();

        PresidentialPardonForm    &operator=(const PresidentialPardonForm &instance);

        virtual void execute(Bureaucrat const &Bureaucrat) const;
    
    private:
        std::string _target;
};

#endif
