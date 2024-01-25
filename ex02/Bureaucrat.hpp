#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade; // 1 (highest) to 150 (lowest).

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        std::string getName(void) const;
        int getGrade(void) const;

        void increment_grade(void);
        void decrement_grade(void);
        
        void signForm(AForm &f);
        void executeForm(const AForm &form) const;

        // EXCEPTION CLASSES
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too high!"; }
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too low!"; }
        };

};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& obj);

#endif
