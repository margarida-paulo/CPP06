NAME = serializer

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

FILES = Serializer.cpp Serializer.hpp

all: ${NAME}

${NAME}: Serializer.cpp Serializer.hpp
	${CPP} ${FLAGS} ${FILES} main.cpp -o ${NAME}

fclean:
	rm ${NAME}

re:
	make fclean
	make