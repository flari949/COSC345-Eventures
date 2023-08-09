CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include -L./bin -g
SRC = data_fetch.cpp
EXECUTABLE = data_fetch.exe

LIBS = -lcurl

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SRC) $(LIBS)

clean:
	rm -f $(EXECUTABLE)