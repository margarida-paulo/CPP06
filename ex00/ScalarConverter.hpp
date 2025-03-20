#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

#define PRECISION 4
#define FLOAT 0
#define DOUBLE 1
#define INT 2
#define CHAR 3

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
    //Orthodox Canonical Form
        ScalarConverter();
	    ScalarConverter(const ScalarConverter& src);
	    ScalarConverter& operator=(const ScalarConverter& src);
	    virtual ~ScalarConverter();
        
        static bool isChar(const std::string &toCheck);
        static bool isSpecialCase(std::string& toCheck);
        static bool isFloat(const std::string &ending);
        static bool isDouble(const std::string &ending);
        static bool isInt(const std::string &ending);
        static void printResult(const std::string &toPrint, int type);
        static void printSpecialCase(const std::string &toPrint);
        static bool isOverflowing(const std::string &toCheck, int type);

};

#endif