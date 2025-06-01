# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -Wall -Wextra -std=c++17

# Source files
SRCS = main.cpp Generate_Q_Table.cpp Check_board.cpp Model_transfer.cpp Train_Model.cpp Model.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = main

# Build target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET)
