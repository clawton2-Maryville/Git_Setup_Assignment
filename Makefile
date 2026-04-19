CXX = g++
CXXFLAGS = -Wall -std=c++11 $(shell xml2-config --cflags)
LDFLAGS = $(shell xml2-config --libs)
TARGET = program
SRC = Source_Code.cpp
all: $(TARGET)
$(TARGET): $(SRC)
  $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)
clean:
  rm -f $(TARGET)
