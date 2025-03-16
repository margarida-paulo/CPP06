NAME = converter

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = ScalarConverter.cpp ScalarConverter.hpp

all: ${NAME}

${NAME}: ScalarConverter.cpp ScalarConverter.hpp
	${CPP} ${FLAGS} ${FILES} main.cpp -o ${NAME}

fclean:
	rm ${NAME}

re:
	make fclean
	make