# 编译器设置
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# 目录设置
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# 默认目标
all: prepare

# 准备构建目录
prepare:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BIN_DIR)

# 编译单个源文件
# 用法: make compile FILE=src/your_file.cpp
compile: prepare
	$(CXX) $(CXXFLAGS) -I$(SRC_DIR) $(FILE) -o $(BIN_DIR)/$(basename $(notdir $(FILE)))

# 运行编译后的程序
# 用法: make run FILE=src/your_file.cpp
run: compile
	$(BIN_DIR)/$(basename $(notdir $(FILE)))

# 清理构建文件
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# 帮助信息
help:
	@echo "使用方法:"
	@echo "  make compile FILE=src/your_file.cpp  - 编译指定的源文件"
	@echo "  make run FILE=src/your_file.cpp      - 编译并运行指定的源文件"
	@echo "  make clean                           - 清理构建文件"

.PHONY: all prepare compile run clean help