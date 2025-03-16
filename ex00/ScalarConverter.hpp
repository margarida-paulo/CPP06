#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

#define PRECISION 4

// Text color codes
# define RESET		"\033[0m"	// Reset color
# define RED		"\033[31m"	// Red
# define GREEN		"\033[32m"	// Green
# define YELLOW		"\033[33m"	// Yellow
# define BLUE		"\033[34m"	// Blue
# define MAGENTA	"\033[35m"	// Magenta
# define CYAN		"\033[36m"	// Cyan
# define WHITE		"\033[37m"	// White

class ScalarConverter{
    public:
        static void convert(std::string toConvert);

    private:
        static bool isChar(std::string toCheck);
        static void printResult(double toPrint);
};