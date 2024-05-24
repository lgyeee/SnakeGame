# Makefile

# Compiler and options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
#LDFLAGS = -L/home/weiwei/Snake_Project/SFML-2.6.1/lib

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Project source files
SRCS = main.cpp Game.cpp Snake.cpp Fruit.cpp ScoreBoard.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable file
TARGET = SnakeGame

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

