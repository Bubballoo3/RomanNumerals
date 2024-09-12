CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = main
OBJS = main.o Roman.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Roman.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Roman.o: Roman.cpp Roman.h
	$(CXX) $(CXXFLAGS) -c Roman.cpp

clean:
	rm -f $(OBJS) $(TARGET)
