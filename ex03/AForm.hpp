#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExec;
        AForm();

    public:
        AForm(std::string name, int gradeSign);
        AForm(std::string name, int gradeSign, int gradeExecute);
        ~AForm();
        AForm(const AForm &rhs);
        AForm& operator=(const AForm &rhs);

        std::string get_name(void) const;
        int get_gradeSign(void) const;
        int get_gradeExec(void) const;
        bool get_isSigned(void) const;

        void beSigned(const Bureaucrat &brc);
        virtual void execute(Bureaucrat const & executor) const = 0;

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
        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char *what() const throw() { return "Grade too low to sign Form."; }
        };
};

/*
Soyut sınıfların içinde saf sanal fonksiyonlar olmasının yanı sıra, soyut olmayan (normal) üye fonksiyonlar, veri elemanları ve diğer öğeler de bulunabilir. Ancak, en az bir saf sanal fonksiyonun olması, sınıfın soyut kabul edilmesi için yeterlidir.
*/

std::ostream& operator<<(std::ostream &out, const AForm& rhs);

#endif
