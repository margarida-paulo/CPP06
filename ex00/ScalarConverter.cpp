#include "ScalarConverter.hpp"


void ScalarConverter::printResult(double toPrint)
{
	//Prints the char version of toPrint
	if (toPrint < std::numeric_limits<char>::min() || toPrint > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(toPrint)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(toPrint) << "'" << std::endl;

	//Prints the int conversion of toPrint
	if (!(toPrint >= std::numeric_limits<int>::min() && toPrint <= std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(toPrint) << std::endl;

	//Prints the float conversion of toPrint
	std::cout << "float: " << static_cast<float>(toPrint) << "f" << std::endl;
    //	std::cout << "float: " << std::fixed << std::setprecision(PRECISION) << static_cast<float>(toPrint) << "f" << std::endl;


	//Prints toPrint in it's double form
	std::cout << "double: " << toPrint << std::endl;
	//std::cout << "double: " << std::fixed << std::setprecision(PRECISION) << toPrint << std::endl;

}

bool ScalarConverter::isChar(std::string toCheck){
    if (toCheck.length() == 3 && toCheck[0] == '\'' && toCheck[2] == '\'')
        return true;
    return false;
}

void ScalarConverter::convert(std::string toConvert){
    if (ScalarConverter::isChar(toConvert)){
        ScalarConverter::printResult(static_cast<double>(toConvert[1]));
        return;
    }
    char *endOfNumber;
    double number = std::strtod(toConvert.c_str(), &endOfNumber);
    std::string ending(endOfNumber);
    if (ending.length() != 0 &&((ending.length() > 1 || ending[0] != 'f')))
        std::cout << RED << "Invalid input" << RESET << std::endl;
    else
        printResult(static_cast<double>(number));
}
