#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{   std::cout << "ShrubberyCreationForm constructor called." << std::endl; }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs): AForm(rhs)
{ *this = rhs; }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    std::cout << "ShrubberyCreationForm assigment function called." << std::endl;
    if (this != &rhs)
        this->_target = rhs._target; // if cant call direct _target -> write getTarget()
        // this->_target = rhs.getTarget();
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!get_isSigned())
        throw FormNotSignedException();
    if (this->get_gradeExec() < executor.getGrade())
        throw GradeTooLowException();
    
    std::ofstream file( this->get_name() + "_shrubbery" );
    file << "#############################################################################" << std::endl << std::endl;
    file << "                                * "<< std::endl;
    file << "                              ****"<< std::endl;
    file << "                            *******" << std::endl;
    file << "                           **********" << std::endl;
    file << "                        *************O*" << std::endl;
    file << "                      ~~~~~~~~~~~~~~~~~~~~" << std::endl;
    file << "                    ********O***************" << std::endl;
    file << "                   *******************O*******" << std::endl;
    file << "                 ****************O**************" << std::endl;
    file << "               *********O********************O****" << std::endl;
    file << "            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    file << "          *******O*****************O*************O*****" << std::endl;
    file << "       ****************O*************************O*******" << std::endl;
    file << "     ******O******************************************O*****" << std::endl;
    file << "   *******************O***************O***********************" << std::endl;
    file << "                               |HHHHH|" << std::endl;
    file << "                               |HHHHH|" << std::endl;
    file << "                               |HHHHH|" << std::endl;
    file << "                               |HHHHH|" << std::endl;
    file << "                               |HHHHH|" << std::endl;
    file << "                               |H1HH1|" << std::endl;
    file << "                             |111HHH111|" << std::endl;
    file << "                           |1H1HH1H11H1HH|" << std::endl;
    file << "                       |HH11HH1HH1H11H1HH11H|" << std::endl << std::endl;
    file << "#############################################################################" << std::endl;
    file.close();
}

