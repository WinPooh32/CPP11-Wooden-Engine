
#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = map_demo

#OBJS specifies which files to compile as part of the project
OBJS = Tile.o LTexture.o Dot.o Main.o

Tile.o: Tile.cpp Tile.h Constants.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c Tile.cpp

LTexture.o: LTexture.cpp LTexture.h Constants.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c LTexture.cpp

Dot.o: Dot.cpp Dot.h Constants.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c Dot.cpp
Gui.o: gui.cpp
	$(CC) $(COMPILER_FLAGS) -c gui.cpp

Main.o: Main.cpp Tile.h LTexture.h Dot.h Constants.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c Main.cpp
Gui: gui.o
	$(CC) gui.o $(COMPILER_FLAGS)  -o Gui

$(OBJ_NAME): Main.o Tile.o LTexture.o Dot.o
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

#This is the target that compiles our executable
all : $(OBJ_NAME) Gui

.PHONY: clean
clean:
	rm -f *.o $(OBJ_NAME) Gui
