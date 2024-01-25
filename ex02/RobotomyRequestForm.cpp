#include "RobotomyRequestForm.hpp"
#include <cstdlib> // srand() - rand() - for windows

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{   std::cout << "RobotomyRequestForm constructor called." << std::endl; }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs): AForm(rhs)
{ *this = rhs; }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    std::cout << "RobotomyRequestForm assigment function called." << std::endl;
    (void)rhs;
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!get_isSigned())
        throw FormNotSignedException();
    if (this->get_gradeExec() < executor.getGrade())
        throw GradeTooLowException();
    srand(time(0));
    std::cout << "RrrrobotVoicccee" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
	else
		std::cout << this->_target << "'s robotization process failed!" << std::endl;
}

