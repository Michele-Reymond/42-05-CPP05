#ifndef SHRUBBERYCREATIONSFORM_HPP
# define SHRUBBERYCREATIONSFORM_HPP

# include <iostream>
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form {

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string name, std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& instance);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm    &operator=(const ShrubberyCreationForm &instance);

        virtual void execute(Bureaucrat const &Bureaucrat) const;
    
    private:
        std::string _target;
};

#endif
