CXX = g++
CXXFLAGS = -Iinclude -Wall -g -std=c++23
SRC = src/Main.cpp src/Middleware.cpp src/Service.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = 01_Birthofexe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

