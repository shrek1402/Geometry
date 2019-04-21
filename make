CC=g++
CFLAGS=-std=c++14
SOURCES=Geometry2/Figure.cpp Geometry2/Triangle.cpp Geometry2/Poligone.cpp Geometry2/Circle.cpp Geometry2/Input.cpp Geometry2/Geometry2.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Geometry

all:
	g++ -std=c++14 Geometry2/Figure.cpp Geometry2/Triangle.cpp Geometry2/Poligone.cpp Geometry2/Circle.cpp Geometry2/Input.cpp Geometry2/Geometry2.cpp -o ABC
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o Geometry
