#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        const std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &rhs);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);

        void execute(const Bureaucrat & executor) const;
};

#endif
