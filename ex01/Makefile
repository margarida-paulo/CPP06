NAME = serializer

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Serializer.cpp

HEADERS = Serializer.hpp

MAIN = main.cpp

OBJ = $(MAIN:.cpp=.o) $(SRC:.cpp=.o)

all : ${NAME}

${NAME}: ${OBJ}
	@echo "Compiling into object files"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled successfuly!"

%.o: %.cpp ${HEADERS}
	@echo "Compiling $< into object file"
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf ${OBJ}
	@echo "Object files deleted."

fclean : clean
	@rm -rf ${NAME}
	@echo "Executable deleted."

re:
	@make fclean
	@make