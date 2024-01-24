#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{   std::cout << "RobotomyRequestForm constructor called." << std::endl; }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs): AForm(rhs)
{ *this = rhs; }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    std::cout << "RobotomyRequestForm assigment function called." << std::endl;
    (void)rhs; // diğer türlü hata verdi.
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!get_isSigned())
        throw FormNotSignedException();
    if (this->get_gradeExec() < executor.getGrade())
        throw GradeTooLowException();
    std::cout << "RrrrobotVoicccee" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << executor.getName() <<  " has been robotomized successfully.";
    if (rand() % 2 == 0)
        std::cout << executor.getName() <<  " the robotomy failed.";
}
