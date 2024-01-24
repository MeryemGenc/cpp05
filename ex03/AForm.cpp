#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeSign): _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(_gradeSign)
{
    if (gradeSign > 150)
        throw AForm::GradeTooLowException();
    if (gradeSign < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec): _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeSign > 150)
        throw AForm::GradeTooLowException();
    if (gradeSign < 1)
        throw AForm::GradeTooHighException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &rhs): _name( rhs.get_name()), _gradeSign( rhs.get_gradeSign() ), _isSigned(get_isSigned()) , _gradeExec( rhs.get_gradeExec() ) {}

AForm& AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs.get_isSigned();
    return (*this);
}

std::string AForm::get_name(void) const { return this->_name; }

int AForm::get_gradeSign(void) const { return this->_gradeSign; }

int AForm::get_gradeExec(void) const { return this->_gradeExec; }

bool AForm::get_isSigned(void) const { return this->_isSigned; }

void AForm::beSigned(const Bureaucrat &brc)
{
    if (brc.getGrade() > this->_gradeSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

std::ostream& operator<<(std::ostream &out, const AForm &rhs)
{
    out << "name: " << rhs.get_name() << std::endl;
    out << "isSigned: " << rhs.get_isSigned() << std::endl;
    out << "gradeSign: " << rhs.get_gradeSign() << std::endl;
    out << "gradeExec: " << rhs.get_gradeExec() << std::endl;
    return out;
}

