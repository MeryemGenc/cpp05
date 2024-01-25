#include "RobotomyRequestForm.hpp"
#include <cstdlib> // srand() - rand()

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{ }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs): AForm(rhs)
{ *this = rhs; }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    (void)rhs; // diğer türlü hata verdi.
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
	{
		int i = 0;
		while(i < 100) // ne oldu şimdi ????
		{
			if (i == 50)
				std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
			i++;
		}
		std::cout << this->_target << "'s robotization process has been completed successfully" << std::endl;
	}
	else
	{
		std::cout << this->_target << "'s robotization process failed!" << std::endl;
	}
}

