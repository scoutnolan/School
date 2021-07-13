# Inheritence makefile
demo: Shape.o main.o Triangle.o
	g++ main.o Shape.o Triangle.o -o ShapeDemo

main: main.cpp Rectangle.cpp Shape.cpp
	g++ -c main.cpp

Triangle.o:  Triangle.cpp Triangle.hpp
	g++ -c Triangle.cpp Triangle.hpp

Shape.o: Shape.cpp Shape.hpp
	g++ -c Shape.cpp Shape.hpp 

clean:
	rm ShapeDemo *.o *.gch

