CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = program
OBJ = glowny.o wektor.o

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

glowny.o: glowny.cpp wektor.h
	$(CXX) $(CXXFLAGS) -c glowny.cpp

wektor.o: wektor.cpp wektor.h
	$(CXX) $(CXXFLAGS) -c wektor.cpp

clean:
	rm -f $(OBJ) $(TARGET)
