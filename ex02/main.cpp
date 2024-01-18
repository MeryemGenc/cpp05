#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
    // AForm f("form1", 20); // not allowed - AForm is abstract class
    {
        std::cout << std::endl << "Test 1" << std::endl;
        try {
            Bureaucrat b("Buro", 5);
            std::cout << b;
            ShrubberyCreationForm f1("ayse");
            RobotomyRequestForm f2("fatma");
            PresidentialPardonForm f3("ali");

            std::cout << f1;
            std::cout << f2;
            std::cout << f3;

            b.signForm(f1);
            b.signForm(f2);
            b.signForm(f3);

            f1.execute(b);
            f2.execute(b);
            f3.execute(b);
        }
        catch (const std::exception&e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl << "Test 2" << std::endl;
        try {
            Bureaucrat b("Buro", 50);
            std::cout << b;
            ShrubberyCreationForm f1("ayse");
            RobotomyRequestForm f2("fatma");
            PresidentialPardonForm f3("ali");

            std::cout << f1;
            std::cout << f2;
            std::cout << f3;

            b.signForm(f1);
            b.signForm(f2);
            b.signForm(f3);
            
            f1.execute(b);
            f2.execute(b);
            f3.execute(b);
        }
        catch (const std::exception&e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
