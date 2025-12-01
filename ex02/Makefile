name = NOW_WE_ARE_TALKING

CXX = c++

cxxflags = -Wall -Wextra -Werror -std=c++98

src = Fixed.cpp main.cpp

obj = $(src:.cpp=.o)

all: $(name)

$(name): $(obj)
	$(CXX) $(cxx) -o $@ $^

%.o: %.cpp
	$(CXX) $(cxx) -c $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(name)

re: fclean all
