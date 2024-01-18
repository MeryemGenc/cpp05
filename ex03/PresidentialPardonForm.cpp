#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{   std::cout << "PresidentialPardonForm constructor called." << std::endl; }

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs): AForm(rhs)
{ *this = rhs; }

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    std::cout << "PresidentialPardonForm assigment function called." << std::endl;
    if (this != &rhs)
        this->_target = rhs._target; // if cant call direct _target -> write getTarget()
        // this->_target = rhs.getTarget();
    return (*this);
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!get_isSigned())
        throw FormNotSignedException();
    if (this->get_gradeExec() < executor.getGrade())
        throw GradeTooLowException();
    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
