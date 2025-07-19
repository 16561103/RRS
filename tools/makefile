# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++17
INCLUDES = -I../include

# Directories
SRC_DIR = ../src
BUILD_DIR = ../build
BIN_DIR = ../bin

# Sources and objects
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Target binary
TARGET = $(BIN_DIR)/reservation

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile each .cpp into .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "🧹 Cleaning build and bin directories..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean

