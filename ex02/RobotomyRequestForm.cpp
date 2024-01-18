#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{   std::cout << "RobotomyRequestForm constructor called." << std::endl; }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs): AForm(rhs)
{ *this = rhs; }

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    std::cout << "RobotomyRequestForm assigment function called." << std::endl;
    if (this != &rhs)
        this->_target = rhs._target; // if cant call direct _target -> write getTarget()
        // this->_target = rhs.getTarget();
    return (*this);
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
