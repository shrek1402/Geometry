CC=g++
CFLAGS=-std=c++11
SOURCES=Geometry2/Geometry2.cpp Geometry2/pch.cpp Geometry2/Circle.cpp Geometry2/Figure.cpp Geometry2/Poligone.cpp Geometry2/Triangle.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Geometry

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o Geometry
