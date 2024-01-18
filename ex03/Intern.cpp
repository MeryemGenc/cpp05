#include "Intern.hpp"

Intern::Intern(){ std::cout << "Intern constructor called." << std::endl; }

Intern::~Intern() { std::cout << "Intern destructor called." << std::endl; }

Intern::Intern(Intern const &rhs) { *this = rhs; std::cout << "Intern copy constructor called." << std::endl; }

Intern& Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    std::cout << "Intern assigment function called." << std::endl;
    return (*this);
}

AForm* presidentialFormFunc(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* shrubberyFormFunc(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* robotomyFormFunc(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *makeForm(std::string formName, std::string targetName)
{
    typedef AForm* (*formFunc)(std::string target); // first () is must.
    std::string funcNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    formFunc functions[] = {&shrubberyFormFunc, &robotomyFormFunc, &presidentialFormFunc};

    for (int i = 0; i < 3; i++)
    {
        if (funcNames[i] == formName)
        {
            std::cout << "Intern creates" << formName << " form" << std::endl;
            return (functions[i](targetName)); // sorun çıkarsa return ((functions[i])(targetName))
        }
    }
    std::cout << "Couldnt created " << formName << " form" << std::endl;
    return NULL;
}






