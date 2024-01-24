#include "Form.hpp"

// ??? önce _name(name) şeklindeki atamalar mı çalışır, yoksa constructor içi mi çalışır? Constructor içi olması gerek ki fonksiyon doğru çalışsın.
Form::Form(const std::string name, int gradeSign): _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(_gradeSign)
{
    if (gradeSign > 150)
        throw Form::GradeTooLowException();
    if (gradeSign < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const std::string name, int gradeSign, int gradeExec): _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeSign > 150)
        throw Form::GradeTooLowException();
    if (gradeSign < 1)
        throw Form::GradeTooHighException();
}

Form::~Form() {}

Form::Form(const Form &rhs): _name( rhs.get_name()), _gradeSign( rhs.get_gradeSign() ), _isSigned(get_isSigned()) , _gradeExec( rhs.get_gradeExec() ) {}

Form& Form::operator=(const Form &rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs.get_isSigned(); // other ones are const - not mofiable value
    return (*this);
}

std::string Form::get_name(void) const { return this->_name; }

int Form::get_gradeSign(void) const { return this->_gradeSign; }

int Form::get_gradeExec(void) const { return this->_gradeExec; }

bool Form::get_isSigned(void) const { return this->_isSigned; }

std::ostream& operator<<(std::ostream &out, const Form &rhs)
{
    out << "name: " << rhs.get_name() << std::endl;
    out << "isSigned: " << rhs.get_isSigned() << std::endl;
    out << "gradeSign: " << rhs.get_gradeSign() << std::endl;
    out << "gradeExec: " << rhs.get_gradeExec() << std::endl;
    return out;
}

void Form::beSigned(const Bureaucrat &brc) // It changes the form status to signed if the bureaucrat’s grade is high enough - egal
{
    if (brc.getGrade() > this->_gradeSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}


