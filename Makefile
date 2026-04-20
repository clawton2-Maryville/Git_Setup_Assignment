CXX = g++
CXXFLAGS = -Wall -std=c++11 $(shell xml2-config --cflags)
LDFLAGS = $(shell xml2-config --libs)
TARGET = book_titles
SRC = book_titles.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)


