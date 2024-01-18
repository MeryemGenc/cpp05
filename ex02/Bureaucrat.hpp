#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade; // 1 (highest) to 150 (lowest).

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);

        std::string getName(void) const;
        int getGrade(void) const;

        void increment_grade(void);
        void decrement_grade(void);
        
        void signForm(AForm &f);
        void executeForm(AForm const & form);

        class GradeTooHighException: public std::exception // Exception classes don’t have to be designed in Orthodox Canonical Form.
        {
            public:
                virtual const char* what() const throw() { return "Grade is too high!"; } // bu satırın çalışma mantığı nedir hala anlamadım.!
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade is too low!"; }
        };

};

std::ostream& operator<<(std::ostream &out, Bureaucrat const& obj);

/*
               ***************** virtual const char* what() const throw();
virtual: Bu anahtar kelime, bu fonksiyonun sanal (virtual) bir fonksiyon olduğunu belirtir. Sanal fonksiyonlar, bu fonksiyonun alt sınıflar tarafından ezilebileceği anlamına gelir. Yani, türetilmiş sınıflar kendi what fonksiyonlarını uygulayabilir ve temel sınıftaki what fonksiyonunu geçersiz kılabilir.

const char* what() const: Bu kısım, what fonksiyonunun tanımını içerir. const char* türünde bir değer döndürdüğünü ve hiçbir parametre almadığını belirtir. Bu fonksiyon genellikle bir istisna nesnesinin hata açıklamasını (error description) döndürmek için kullanılır.

throw(): Bu kısım, bu fonksiyonun hiçbir durumda istisna fırlatmayacağını belirtir. Yani, bu fonksiyonun içindeki herhangi bir hata durumunda istisna oluşturulmayacaktır. Bu, C++'ın eski bir istisna spesifikasyonu anlamına gelir ve modern C++'da genellikle kullanılmaz. Modern C++ standartları, noexcept anahtar kelimesini kullanmayı ve bu tür bir belirtinin terk edilmesini önerir. Ancak, eski kod tabanlarında hâlâ kullanılabilir.

*/

#endif
