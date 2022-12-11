#include "ShrubberyCreationForm.hpp"

// ---------Constructor and destructor ------------

ShrubberyCreationForm::ShrubberyCreationForm() : Form(145, 137, "ShrubberyCreationForm 101"), _target("shrubbery") {
    std::cout << "A new \"ShrubberyCreationForm 101\" is out" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : 
        Form(145, 137, name),
        _target(target) {
    std::cout << "ShrubberyCreationForm \"" << name << "\": is out" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& instance) {
    *this = instance;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructed" << std::endl;
}

// --------- Fonctions ------------

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
    this->canExecute(bureaucrat);
	std::ofstream file(this->_target + "_shrubbery");
	for (int i = 0; i < 3; i++)
	{
		file << "      ." << std::endl;
		file << "   __/ \\__" << std::endl;
		file << "   \\     /" << std::endl;
		file << "   /.'o'.\\" << std::endl;
		file << "    .o.'." << std::endl;
		file << "   .'.'o'." << std::endl;
		file << "  o'.o.'.o." << std::endl;
		file << " .'.o.'.'.o." << std::endl;
		file << ".o.'.o.'.o.'." << std::endl;
		file << "   [_____]" << std::endl;
		file << "    \\___/" << std::endl << std::endl << std::endl;
	}
	file.close();
	std::cout << "5 trees were planted in " << this->_target << std::endl;
}

// --------- Operator overload ------------

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &instance) {
    std::cout << "A ShrubberyCreationForm is copied" << std::endl;
    this->setGradeToSign(instance.getGradeToSign());
    this->setGradeToExecute(instance.getGradeToExecute());
    this->setSignStatus(instance.getSignStatus());
    return *this;
}
