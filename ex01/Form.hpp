#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExec;
        Form();

    public:
        Form(std::string name, int gradeSign);
        Form(std::string name, int gradeSign, int gradeExecute);
        ~Form();
        Form(const Form &rhs);
        Form& operator=(const Form &rhs);

        std::string get_name(void) const;
        int get_gradeSign(void) const;
        int get_gradeExec(void) const;
        bool get_isSigned(void) const;

        void beSigned(const Bureaucrat &brc); // It changes the form status to signed if the bureaucrat’s grade is high enough - egal

        // EXCEPTION CLASSES
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw() { return "Grade too high."; }
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw() { return "Grade too low."; }
        };
};

std::ostream& operator<<(std::ostream &out, const Form& rhs);

#endif
