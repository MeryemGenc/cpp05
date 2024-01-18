#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        std::string _name;
        bool _isSigned;
        int _gradeSign;
        int _gradeExec;
        AForm();
    public:
        AForm(std::string name, int gradeSign, int gradeExec);
        ~AForm();
        AForm(AForm const &rhs);
        AForm& operator=(AForm const &rhs);

        std::string get_name(void) const;
        int get_gradeSign(void) const;
        int get_gradeExec(void) const;
        bool get_isSigned(void) const;

        void beSigned(Bureaucrat const &brc); // It changes the form status to signed if the bureaucrat’s grade is high enough - egal
        virtual void execute(Bureaucrat const & executor) const = 0;

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
        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char *what() const throw() { return "Grade is too low."; }
        };
};

/*
Soyut sınıfların içinde saf sanal fonksiyonlar olmasının yanı sıra, soyut olmayan (normal) üye fonksiyonlar, veri elemanları ve diğer öğeler de bulunabilir. Ancak, en az bir saf sanal fonksiyonun olması, sınıfın soyut kabul edilmesi için yeterlidir.
*/

std::ostream& operator<<(std::ostream &out, AForm const& rhs);

#endif
