# 定义编译器和编译选项
CC = gcc
CFLAGS = -Wall -I./include 
LDFLAGS = -lwiringPi -lpthread

# 定义目标文件路径
OBJ_DIR = obj
BIN_DIR = bin

# 获取源文件列表
SRC_DIRS = hardware tcp_server .
SRCS = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
TARGET = $(BIN_DIR)/raspi_server

# 默认目标
all: $(TARGET)

# 编译目标文件
$(OBJ_DIR)/%.o: hardware/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: tcp_server/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR)/%.o: ./%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# 清理生成的文件
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean
