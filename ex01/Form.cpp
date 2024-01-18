#include "Form.hpp"

// ??? önce _name(name) şeklindeki atamalar mı çalışır, yoksa constructor içi mi çalışır? Constructor içi olması gerek ki fonksiyon doğru çalışsın.
Form::Form(std::string name, int gradeSign): _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(_gradeSign)
{
    if (gradeSign > 150)
        throw Form::GradeTooLowException();
    if (gradeSign < 1)
        throw Form::GradeTooHighException();
}

Form::~Form() {}

Form::Form(Form const &rhs)
{
    *this = rhs;
}

Form& Form::operator=(Form const &rhs)
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

std::string Form::get_name(void) const { return this->_name; }

int Form::get_gradeSign(void) const { return this->_gradeSign; }

int Form::get_gradeExec(void) const { return this->_gradeExec; }

bool Form::get_isSigned(void) const { return this->_isSigned; }

std::ostream& operator<<(std::ostream &out, Form const &rhs)
{
    out << "name: " << rhs.get_name() << std::endl;
    out << "isSigned: " << rhs.get_isSigned() << std::endl;
    out << "gradeSign: " << rhs.get_gradeSign() << std::endl;
    out << "gradeExec: " << rhs.get_gradeExec() << std::endl;
    return out;
}

void Form::beSigned(Bureaucrat const &brc) // It changes the form status to signed if the bureaucrat’s grade is high enough - egal
{
    if (brc.getGrade() > this->_gradeSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}


