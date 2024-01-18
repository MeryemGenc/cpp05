#include "Bureaucrat.hpp"

int main( void )
{
    {
        Bureaucrat b("Haci", 5);
        Form f("form1", 20);

        std::cout << f;
        b.signForm(f);
        std::cout << f;
    }
    {
        Bureaucrat b("Haci", 25);
        Form f("form1", 20);

        std::cout << f;
        b.signForm(f);
        std::cout << f;
    }

    return 0;
}
