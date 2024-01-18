#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        std::string _name;
        bool _isSigned;
        int _gradeSign;
        int _gradeExec;
        Form();
    public:
    Form(std::string name, int gradeSign);
    ~Form();
    Form(Form const &rhs);
    Form& operator=(Form const &rhs);

    std::string get_name(void) const;
    int get_gradeSign(void) const;
    int get_gradeExec(void) const;
    bool get_isSigned(void) const;

    void beSigned(Bureaucrat const &brc); // It changes the form status to signed if the bureaucrat’s grade is high enough - egal

    class GradeTooHighException: public std::exception
    {
        public:
            virtual const char *what() const throw() { return "Grade is too high."; }
    };
    class GradeTooLowException: public std::exception
    {
        public:
            virtual const char *what() const throw() { return "Grade is too low."; }
    };
};

std::ostream& operator<<(std::ostream &out, Form const& rhs);

#endif
