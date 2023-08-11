CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include -g
LIBS = -L./lib -lcurl

SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

EXECUTABLE = app.exe

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SRC_FILES) $(LIBS)

clean:
	rm -f $(EXECUTABLE)