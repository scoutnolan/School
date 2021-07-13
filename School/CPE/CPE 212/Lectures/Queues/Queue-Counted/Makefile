demo: QueueType.o Queue.o main.o
	g++ -std=c++11 main.o QueueType.o Queue.o -o Queue_Counted

main: main.cpp queue.cpp queue.h
	g++ -std=c++11 main.cpp

Queue.o: queue.cpp queue.h queueType.h
	g++ -c -std=c++11 queue.cpp queue.h

QueueType.o: queueType.cpp queueType.h
	g++ -c -std=c++11 queueType.cpp queueType.h	

clean:
	rm -f Queue_Counted *.o *.gch