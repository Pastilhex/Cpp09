NAME = PmergeMe
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CFLAGS = -Wall -Werror -Wextra -g -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all re clean fclean