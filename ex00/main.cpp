#include "Bureaucrat.hpp"

int main( void )
{
    {
        Bureaucrat b("Haci", 1);
        std::cout << b << std::endl;
        try {
            b.increment_grade();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << b << std::endl;

        // try {
        //     b1.increment_grade();
        // } catch (Bureaucrat::GradeTooHighException &e) {
        //     std::cout << e.what() << std::endl;
        // }
        // std::cout << b1 << std::endl;
    }

    {
        Bureaucrat b("Haci", 150);
        std::cout << b << std::endl;
        try {
            b.decrement_grade();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << b << std::endl;

        // try {
        //     b.decrement_grade();
        // } catch (Bureaucrat::GradeTooHighException &e) {
        //     std::cout << e.what() << std::endl;
        // }
        // std::cout << b << std::endl;
    }

    return 0;
}
