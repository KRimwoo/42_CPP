CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = src
INCDIR = includes

SRCS = $(SRCDIR)/Animal.cpp $(SRCDIR)/Cat.cpp $(SRCDIR)/Dog.cpp \
	$(SRCDIR)/WrongAnimal.cpp $(SRCDIR)/WrongCat.cpp \
	$(SRCDIR)/WrongDog.cpp $(SRCDIR)/main.cpp $(SRCDIR)/Brain.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = ex02

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all