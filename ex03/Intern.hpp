#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(Intern const &rhs);
        Intern& operator=(Intern const &rhs);

        AForm *makeForm(std::string formName, std::string targetName);
};

#endif
