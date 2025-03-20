#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP
#include <string>
#include <iostream>

// Text color codes
# define RESET		"\033[0m"	// Reset color
# define RED		"\033[31m"	// Red
# define GREEN		"\033[32m"	// Green
# define YELLOW		"\033[33m"	// Yellow
# define BLUE		"\033[34m"	// Blue
# define MAGENTA	"\033[35m"	// Magenta
# define CYAN		"\033[36m"	// Cyan
# define WHITE		"\033[37m"	// White
# define BOLD       "\033[1m"   // Bold

typedef unsigned long uintptr_t;

typedef struct DataStuff{
    std::string name;
    std::string surname;
} Data;

class Serializer{
    private:
    Serializer();
    Serializer(const Serializer& src);
    Serializer& operator=(const Serializer& src);
    virtual ~Serializer();

    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif