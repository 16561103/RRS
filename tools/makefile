# Compiler and flags
cc = g++
CFLAGS = -g -Wall -Wextra
INCLUDES = -I../include

# Directories (relative to tools/)
SRC_DIR = ../src
INC_DIR = ../include
BUILD_DIR = ../build
BIN_DIR = ../bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Target executable
TARGET = $(BIN_DIR)/reservation

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(cc) $(CFLAGS) $(OBJS) -o $(TARGET)

# Pattern rule to compile .cpp -> .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(cc) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean rule
clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean

