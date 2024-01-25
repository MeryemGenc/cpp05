#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{ }

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs): AForm(rhs), _target(rhs._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
        this->_target = rhs._target;
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
    if (!get_isSigned())
        throw FormNotSignedException();
    if (this->get_gradeExec() < executor.getGrade())
        throw GradeTooLowException();
    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
