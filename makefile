# Makefile

# 編譯器和選項
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -I/opt/homebrew/Cellar/sfml/2.6.1/include
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.1/lib

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# 項目源文件
SRCS = src/main.cpp src/Game.cpp src/Snake.cpp src/Fruit.cpp src/ScoreBoard.cpp
HDRS = include/Game.h include/Snake.h include/Fruit.h include/ScoreBoard.h

# 可執行文件
TARGET = build/SnakeGame

# 預設目標
all: $(TARGET) copy-resources

# 複製資源文件到建構目錄
copy-resources: 
	cp -r assets build/assets

# 建立可執行文件的規則
$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS) $(LIBS)

# 清理產生的檔案
clean:
	rm -f $(TARGET)
	rm -rf copy-resources
	rm -f *.o
