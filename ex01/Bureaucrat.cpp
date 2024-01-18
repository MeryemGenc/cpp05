#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(50) 
{
    std::cout << "Default constructor called. Grade is: " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) 
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this!= &other)
        this->_grade = other.getGrade();
    return (*this);
}

std::string Bureaucrat::getName(void) const { return this->_name; }

int Bureaucrat::getGrade(void) const { return this->_grade; }

void Bureaucrat::increment_grade(void)
{
    if (this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrement_grade(void)
{
    if (this->_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned((*this));
        std::cout << this->_name << " signed " << f.get_name() << std::endl; 
    } 
    catch (Form::GradeTooLowException &e)
    {
        std::cout << this->_name << " couldn't sign " << f.get_name() << " because " << e.what() << std::endl; 
    }
}


std::ostream& operator<<(std::ostream &out, Bureaucrat const& obj)
{
    out << obj.getName() << " has grade: " << obj.getGrade() << std::endl;
    return out;
}
