all: game

game: game.o item.o character.o party.o inventory.o warrior.o mage.o rogue.o goblin.o cleric.o
	g++ -std=c++11 game.o item.o party.o character.o inventory.o warrior.o mage.o rogue.o goblin.o cleric.o -o Game

game.o: game.cpp item.cpp character.hpp party.hpp inventory.hpp warrior.hpp mage.hpp rogue.hpp goblin.hpp cleric.hpp
	g++ -std=c++11 -c game.cpp

item.o: item.cpp item.h
	g++ -std=c++11 -c item.cpp

character.o: character.cpp character.hpp list.hpp
	g++ -std=c++11 -c character.cpp

inventory.o: inventory.cpp inventory.hpp
	g++ -std=c++11 -c inventory.cpp

party.o: party.cpp party.hpp
	g++ -std=c++11 -c party.cpp

warrior.o: warrior.cpp warrior.hpp character.hpp
	g++ -std=c++11 -c warrior.cpp

mage.o: mage.cpp mage.hpp character.hpp 
	g++ -std=c++11 -c mage.cpp

rogue.o: rogue.cpp rogue.hpp character.hpp
	g++ -std=c++11 -c rogue.cpp

cleric.o: cleric.cpp cleric.hpp character.hpp
	g++ -std=c++11 -c cleric.cpp

goblin.o: goblin.cpp goblin.hpp character.hpp
	g++ -std=c++11 -c goblin.cpp

.PHONY: all

clean:
	rm *.o Game