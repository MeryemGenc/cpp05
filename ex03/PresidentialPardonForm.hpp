#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &rhs);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);

        void execute(const Bureaucrat &executor) const; 
};

#endif
