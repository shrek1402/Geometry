GXX=g++
CFLAGS=-std=c++14
SOURCES=Geometry2/Figure.cpp Geometry2/Triangle.cpp Geometry2/Poligone.cpp Geometry2/Circle.cpp Geometry2/Input.cpp Geometry2/Geometry2.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Geometry

.PHONY: clean

all:
	$(GXX) $(CFLAGS) $(SOURCES) -o ABC
	
clean:
	rm -rf *.o ABC
