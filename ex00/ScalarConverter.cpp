#include "ScalarConverter.hpp"

// Orthodox Canonical Form
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const & src) {
	if (this != &src) {}
	return (*this);
}
ScalarConverter::~ScalarConverter() {}

//////////////////////////////////////////////////////////////////////////////////

bool ScalarConverter::isOverflowing(const std::string &toCheck, int type){
    switch (type) {
        case INT: {
            long int number = strtol(toCheck.c_str(), NULL, 10);

            if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max()){
				if (number < std::numeric_limits<int>::min()){
					std::cerr << RED << "Integer inserted overflows the minimum integer value." << RESET << std::endl; 
				} else
					std::cerr << RED << "Integer inserted overflows the maximum integer value." << RESET << std::endl; 
                return true;
			}
            break;
        }

		case FLOAT: {
			float number = strtol(toCheck.c_str(), NULL, 10);
		
			if (number < -std::numeric_limits<float>::max() || (number < std::numeric_limits<float>::min() && number > -std::numeric_limits<float>::min()) || number > std::numeric_limits<float>::max()){
				if (number < -std::numeric_limits<float>::max() || number < std::numeric_limits<float>::min())
					std::cerr << RED << "Float inserted underflows the minimum float value." << RESET << std::endl; 
				else
					std::cerr << RED << "Float inserted overflows the maximum float value." << RESET << std::endl; 
				return true;
			}			
			break;

		}

        case DOUBLE: {
            double number = strtol(toCheck.c_str(), NULL, 10);
			if (number < -std::numeric_limits<double>::max() || (number < std::numeric_limits<double>::min() && number > -std::numeric_limits<double>::min() )|| number > std::numeric_limits<double>::max()){
				if (number < -std::numeric_limits<double>::max() || number < std::numeric_limits<double>::min())
					std::cerr << RED << "Double inserted underflows the minimum double value." << RESET << std::endl;
				else
					std::cerr << RED << "Double inserted overflows the maximum double value." << RESET << std::endl;
                return true;
			}
            break;
        }
    }
    return false;
}

void ScalarConverter::printResult(const std::string &toPrint, int type)
{
	int integerVersion;
	char charVersion;
	double doubleVersion;
	float floatVersion;

	switch (type){
		case INT: {
			//In the int, we don't check for overflows. We only check for overflows when the conversion could cause an overflow
			integerVersion = std::atoi(toPrint.c_str());
			floatVersion = static_cast<float>(integerVersion);
			doubleVersion = static_cast<double>(integerVersion);
			
			//Prints the char version
			if (integerVersion < std::numeric_limits<char>::min() || integerVersion > std::numeric_limits<char>::max())
				std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(static_cast<char>(integerVersion)))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(integerVersion) << "'" << std::endl;
			
			//Prints the int
			std::cout << "int: " << integerVersion << std::endl;

			//Prints the float
			if (integerVersion < -std::numeric_limits<float>::max() || (integerVersion < std::numeric_limits<float>::min() && integerVersion > -std::numeric_limits<float>::min()) || integerVersion > std::numeric_limits<float>::max())
				std::cout << "float: Overflow/Underflow" << std::endl;
			else
				std::cout << "float: " << floatVersion << "f" << std::endl;

			//Prints the double
			if (integerVersion < -std::numeric_limits<double>::max() || (integerVersion < std::numeric_limits<double>::min() && integerVersion > -std::numeric_limits<double>::min() )|| integerVersion > std::numeric_limits<double>::max())
				std::cout << "double: Overflow/Underflow" << std::endl;
			else
				std::cout << "double: " << doubleVersion << std::endl;
			break;
		}
		case CHAR: {
			charVersion = toPrint[0];
			integerVersion = static_cast<int>(charVersion);
			floatVersion = static_cast<int>(charVersion);
			doubleVersion = static_cast<int>(charVersion);

			std::cout << "char " << charVersion << std::endl;
			std::cout << "int: " << integerVersion << std::endl;
			std::cout << "float: " << floatVersion << "f" << std::endl;
			std::cout << "double: " << doubleVersion << std::endl;
			break;
		}
		case DOUBLE: {
			doubleVersion = std::strtod(toPrint.c_str(), NULL);
			integerVersion = static_cast<int>(doubleVersion);
			floatVersion = static_cast<float>(doubleVersion);

			//Prints the char version
			if (doubleVersion < std::numeric_limits<char>::min() || doubleVersion > std::numeric_limits<char>::max())
				std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(static_cast<char>(doubleVersion)))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(doubleVersion) << "'" << std::endl;

			//Prints the int
			if (doubleVersion < std::numeric_limits<int>::min() || doubleVersion > std::numeric_limits<int>::max())
				std::cout << "int: Overflow" << std::endl;
			else
				std::cout << "int: " << integerVersion << std::endl;

			//Prints the float
			if (doubleVersion < -std::numeric_limits<float>::max() || (doubleVersion < std::numeric_limits<float>::min() && doubleVersion > -std::numeric_limits<float>::min()) || doubleVersion > std::numeric_limits<float>::max())
				std::cout << "float: Overflow/Underflow" << std::endl;
			else
				std::cout << "float: " << floatVersion << "f" << std::endl;

			//Prints the double
			std::cout << "double: " << doubleVersion << std::endl;
			break;
		}

		case FLOAT: {
			floatVersion = std::strtof(toPrint.c_str(), NULL);
			integerVersion = static_cast<int>(floatVersion);
			doubleVersion = static_cast<double>(floatVersion);


			//Prints the char version
			if (floatVersion < std::numeric_limits<char>::min() || floatVersion > std::numeric_limits<char>::max())
				std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(static_cast<char>(floatVersion)))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(floatVersion) << "'" << std::endl;

			//Prints the int
			if (floatVersion < std::numeric_limits<int>::min() || floatVersion > std::numeric_limits<int>::max())
				std::cout << "int: Overflow" << std::endl;
			else
				std::cout << "int: " << integerVersion << std::endl;

			//Prints the float
			std::cout << "float: " << floatVersion << "f" << std::endl;

			//Prints the double
			if (floatVersion < -std::numeric_limits<double>::max() || (floatVersion < std::numeric_limits<double>::min() && floatVersion > -std::numeric_limits<double>::min() )|| floatVersion > std::numeric_limits<double>::max())
				std::cout << "double: Overflow/Underflow" << std::endl;
			else
				std::cout << "double: " << doubleVersion << std::endl;
		}
	}
}

bool ScalarConverter::isChar(const std::string &toCheck){
    if (toCheck.length() == 3 && toCheck[0] == '\'' && toCheck[2] == '\'')
        return true;
    return false;
}

bool ScalarConverter::isFloat(const std::string& toCheck){
	char *endOfNumber;
    std::strtof(toCheck.c_str(), &endOfNumber);
    std::string ending(endOfNumber);
    return (ending.length() == 1 && ending[0] == 'f');
}

bool ScalarConverter::isInt(const std::string& toCheck){
	for (size_t i = 0; i < toCheck.length(); i++){
		if (i == 0 && (toCheck[i] == '-' || toCheck[i] == '+'))
			continue;
		if (!std::isdigit(toCheck[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string& toCheck){
	char *endOfNumber;
    std::strtod(toCheck.c_str(), &endOfNumber);
    std::string ending(endOfNumber);
    return (ending.length() == 0);
}

void ScalarConverter::convert(std::string toConvert){
    if (ScalarConverter::isChar(toConvert)){
        ScalarConverter::printResult(toConvert, CHAR);
    }
	else if (ScalarConverter::isSpecialCase(toConvert)){
		ScalarConverter::printSpecialCase(toConvert);
	} else if (ScalarConverter::isInt(toConvert)){
		//if (isOverflowing(toConvert, INT))
			//return;
		//else
			ScalarConverter::printResult(toConvert, INT);
	} else if (ScalarConverter::isDouble(toConvert)){
		//if (isOverflowing(toConvert, DOUBLE))
			//return;
		//else
			ScalarConverter::printResult(toConvert, DOUBLE);
	} else if (ScalarConverter::isFloat(toConvert)){
		//if (isOverflowing(toConvert, FLOAT))
			//return;
		//else
			ScalarConverter::printResult(toConvert, FLOAT);
	} else {
		std::cerr << RED << "Invalid input" << RESET << std::endl;
	}
}

bool	ScalarConverter::isSpecialCase(std::string& toCheck)
{
	for (size_t i = 0; i < toCheck.length(); i++)
		toCheck[i] = std::tolower(toCheck[i]);
	if (toCheck == "nan" || toCheck == "nanf" ||
			toCheck == "inf" || toCheck == "inff" ||
			toCheck == "+inf" || toCheck == "+inff" ||
			toCheck == "-inf" || toCheck == "-inff")
			return true;
	return false;
}

void	ScalarConverter::printSpecialCase(const std::string &toPrint){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << toPrint << (!(toPrint == "nanf" || toPrint == "inff" || toPrint == "+inff" || toPrint == "-inff") ? "f" : "") << std::endl;
	std::cout << "double: " << ((toPrint == "nanf" || toPrint == "inff" || toPrint == "+inff" || toPrint == "-inff") ? toPrint.substr(0, toPrint.length() - 1) : toPrint) << std::endl;
}


