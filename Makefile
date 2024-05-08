# Name of the binary
BINARY = prototyp5
# Object files
OBJS = character.o hero.o npc.o sorcerer.o fighter.o item.o main.o game.o
# Compiler
CXX = g++
# Compiler flags
CPPFLAGS = -Werror -Wall -I. -std=c++11
# Linker flags
LFLAGS =

# All target: builds all important targets
all: $(BINARY)

# Links the binary
$(BINARY): $(OBJS)
	$(CXX) $(LFLAGS) -o $@ $(OBJS)

# Compiles a source file into an object file
%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

# Rules can not only be used for compiling a program but also for executing a program
run: $(BINARY)
	./$(BINARY)

# Delete all build artifacts
clean:
	rm -rf $(BINARY) $(OBJS)

# All and clean are "phony" targets, meaning they are not files
.PHONY: all clean run