CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = BitcoinExchange.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)

NAME = btc

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re