#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        // TRY

        //Bureaucrat br("Ayse", 30);
        //rrf->beSigned(br);
    }
    {
        Intern someRandomIntern;
        AForm* ppf;
        ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

        // TRY

        //Bureaucrat br("Ayse", 78);
        //ppf->execute(br);
    }

    return 0;
}
