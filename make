GXX=g++
CFLAGS=-std=c++14
SOURCES=Geometry2/Figure.cpp Geometry2/Triangle.cpp Geometry2/Poligone.cpp Geometry2/Circle.cpp Geometry2/Input.cpp Geometry2/Geometry2.cpp
OBJECTS=$(SOURCES:.cpp=.o)
OBJ = g++ $(CFLAGS) -c $< -o $@

EXECUTABLE=Geometry

.PHONY: clean

folder1:
	mkdir -p build
folder2:
	mkdir -p bin

all:
	folder1 folder2 bin/ABC.exe
	
ABC.exe: build/Figure.o build/Triangle.o build/Poligone.o build/Circle.o build/Geometry2.o
	g++ $(CFLAGS) $^ -o $@

build/Figure.o: src/Figure.cpp src/Figure.h
	$(OBJ)
	
build/Geometry2.o: src/Geometry2.cpp
	$(OBJ)
	
build/Circle.o: src/Circle.cpp src/Circle.h
	$(OBJ)
	
build/Poligone.o: src/Poligone.cpp src/Poligone.h
	$(OBJ)

build/Triangle.o: src/Triangle.cpp src/Triangle.h
	$(OBJ)
clean:
	rm -rf *.o ABC
