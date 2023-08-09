CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include -L./bin -g
SRC = data_fetch.cpp process_json.cpp event_request.cpp
EXECUTABLE = app.exe

LIBS = -lcurl

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SRC) $(LIBS)

clean:
	rm -f $(EXECUTABLE)