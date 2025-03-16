#include "ScalarConverter.hpp"
int main(int argc, char **argv){
    if (argc != 2){
        std::cout << "Usage: ./converter <numberToConvert>" << std::endl;
        return (1);
    }
    std::string numberString(argv[1]); 
    ScalarConverter::convert(numberString);
}