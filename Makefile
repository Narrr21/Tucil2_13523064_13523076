CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC_DIR = src
BIN_DIR = bin
TARGET = $(BIN_DIR)/main

# Find all file
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SOURCES))

# Default target
all: build clear run

# Build target (compiles and links)
build: $(TARGET)

# Link the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile each .cpp file to .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Run the program
run:
	./$(TARGET)

# Clean up
clean:
	rm -rf $(BIN_DIR)/*.o $(TARGET)

# Clear terminal and build
clear:
	clear