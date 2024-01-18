#include "AForm.hpp"

// ??? önce _name(name) şeklindeki atamalar mı çalışır, yoksa constructor içi mi çalışır? Constructor içi olması gerek ki fonksiyon doğru çalışsın.
AForm::AForm(std::string name, int gradeSign, int gradeExec): _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeSign > 150)
        throw AForm::GradeTooLowException();
    if (gradeSign < 1)
        throw AForm::GradeTooHighException();
}

AForm::~AForm() {}

AForm::AForm(AForm const &rhs)
{
    *this = rhs;
}

AForm& AForm::operator=(AForm const &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.get_name();
        this->_isSigned = rhs.get_isSigned();
        this->_gradeSign = rhs.get_gradeSign();
        this->_gradeExec = rhs.get_gradeExec();
    }
    return (*this);
}

std::string AForm::get_name(void) const { return this->_name; }

int AForm::get_gradeSign(void) const { return this->_gradeSign; }

int AForm::get_gradeExec(void) const { return this->_gradeExec; }

bool AForm::get_isSigned(void) const { return this->_isSigned; }

std::ostream& operator<<(std::ostream &out, AForm const &rhs)
{
    out << "name: " << rhs.get_name() << std::endl;
    out << "isSigned: " << rhs.get_isSigned() << std::endl;
    out << "gradeSign: " << rhs.get_gradeSign() << std::endl;
    out << "gradeExec: " << rhs.get_gradeExec() << std::endl;
    return out;
}

void AForm::beSigned(Bureaucrat const &brc) // It changes the form status to signed if the bureaucrat’s grade is high enough - egal
{
    if (brc.getGrade() > this->_gradeSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}


