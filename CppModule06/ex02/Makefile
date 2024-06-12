CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Base.cpp A.cpp B.cpp C.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = identify

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