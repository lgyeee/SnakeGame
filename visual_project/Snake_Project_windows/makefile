# Makefile

# 編譯器和選項
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -Isrc/include
LDFLAGS = -Lsrc/lib

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# 項目源文件
SRCS = main.cpp Game.cpp Snake.cpp Fruit.cpp ScoreBoard.cpp
HDRS = Game.h Snake.h Fruit.h ScoreBoard.h

# 可執行文件
TARGET = SnakeGame

# 預設目標
all: $(TARGET)

# 建立可執行文件的規則
$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS) $(LIBS)

# 清理產生的檔案
clean:
	rm $(TARGET)
	rm *.o
