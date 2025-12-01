name = NOW_WE_ARE_TALKING

CXX = c++

cxxflags = -Wall -Wextra -Werror -std=c++98

src = Fixed.cpp main.cpp

obj = $(src:.cpp=.o)

all: $(name)

$(name): $(obj)
	$(CXX) $(cxxflags) -o $@ $^

%.o: %.cpp
	$(CXX) $(cxxflags) -c $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(name)

re: fclean all
