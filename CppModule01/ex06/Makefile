CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Harl.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = ex06

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