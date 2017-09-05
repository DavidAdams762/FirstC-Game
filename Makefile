NAME=thegame

CLANG=clang++ -std=c++11 -stdlib=libc++
CFLAGS=-Wno-unknown-pragmas -g
LDLIBS=-lSDL_image -lSDL_gfx -lSDL_ttf -lstdc++


SRC=$(wildcard *.cpp)
INCLUDE=$(wildcard *.h)
OBJ=$(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) -o $(NAME) $(OBJ) $(LDLIBS) `sdl-config --cflags --libs`

$(SRC):
	$(CLANG) $(CFLAGS) -cpp $< -I$(INCLUDE)

clean:
	rm -rf *.o $(TARGET)

fclean:		clean
		$(RM) $(TARGET)

re:		fclean all
