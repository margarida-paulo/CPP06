NAME = random

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

FILES = A.hpp B.hpp C.hpp Base.cpp Base.hpp

all: ${NAME}

${NAME}: ${FILES}
	${CPP} ${FLAGS} ${FILES} main.cpp -o ${NAME}

fclean:
	rm ${NAME}

re:
	make fclean
	make