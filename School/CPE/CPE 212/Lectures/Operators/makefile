all: main student

student: studentMain.cpp Student.cpp
	g++ -std=c++11 studentMain.cpp Student.cpp -o Student

main: main.cpp
	g++ -std=c++11 main.cpp -o Overloads

clean:
	rm -fr *.o Overloads Student