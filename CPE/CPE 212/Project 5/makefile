all: Project05	

Project05: ProcessQueue.o main.o Process.o PriorityList.o
	g++ -std=c++11 main.o ProcessQueue.o Process.o PriorityList.o -o Project05

Process.o: Process.cpp Process.hpp
	g++ Process.cpp -c -std=c++11

ProcessQueue.o: ProcessQueue.cpp ProcessQueue.hpp Process.hpp
	g++ -c ProcessQueue.cpp -std=c++11 


PriorityList.o: PriorityList.cpp PriorityList.hpp Process.hpp
	g++ PriorityList.cpp -c -std=c++11

main.o: main.cpp ProcessQueue.hpp Process.hpp
	g++ main.cpp -c -std=c++11


.PHONY: all

clean:
	rm *.o Project05
