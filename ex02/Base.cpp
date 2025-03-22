#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
    std::cout << "Base destructor was called" << std::endl;
}

Base *generate(void){
    srand(time(0));
    int randomNumber = rand() % 3;
    Base *randomizedClass;
    switch (randomNumber){
        case 0: {
            randomizedClass = new A();
            break;
        }

        case 1: {
            randomizedClass = new B();
            break;
        }

        case 2: {
            randomizedClass = new C();
            break;
        }
    }
    return randomizedClass;
}

void identify(Base* p){
    if (!p)
        std::cerr << "Null Pointer" << std::endl;
    else if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        throw std::invalid_argument("No class matches the Base reference.");
}

void identify(Base& p){
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &e) {}

    throw std::invalid_argument("No class matches the Base reference.");
}