# Inheritence makefile
demo: Shape.o main.o Square.o
	g++ main.o Shape.o Square.o -o ShapeDemo

main: main.cpp Rectangle.cpp Shape.cpp
	g++ -c main.cpp

Square.o:  Square.cpp Square.hpp
	g++ -c Square.cpp Square.hpp

Shape.o: Shape.cpp Shape.hpp
	g++ -c Shape.cpp Shape.hpp 

clean:
	rm ShapeDemo *.o *.gch

