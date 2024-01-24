#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{   std::cout << "ShrubberyCreationForm constructor called." << std::endl; }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs): AForm(rhs)
{ *this = rhs; }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    std::cout << "ShrubberyCreationForm assigment function called." << std::endl;
    (void)rhs;
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
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

