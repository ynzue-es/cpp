#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
    private:  

    public:
        WrongCat();
        WrongCat(WrongCat const & src);
        ~WrongCat();

        WrongCat& operator=(WrongCat const & rhs);

        void makeSound( void ) const;
};

#endif