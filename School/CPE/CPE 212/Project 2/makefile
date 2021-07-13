game: game.o character.o inventory.o warrior.o mage.o rogue.o goblin.o cleric.o
	g++ game.o character.o inventory.o warrior.o mage.o rogue.o goblin.o cleric.o -o Game -g

game.o: game.cpp character.hpp inventory.hpp warrior.hpp mage.hpp rogue.hpp goblin.hpp cleric.hpp
	g++ -c game.cpp

character.o: character.cpp character.hpp
	g++ -c character.cpp

inventory.o: inventory.cpp inventory.hpp
	g++ -c inventory.cpp

warrior.o: warrior.cpp warrior.hpp character.hpp inventory.hpp
	g++ -c warrior.cpp

mage.o: mage.cpp mage.hpp character.hpp inventory.hpp
	g++ -c mage.cpp

rogue.o: rogue.cpp rogue.hpp character.hpp inventory.hpp
	g++ -c rogue.cpp

cleric.o: cleric.cpp cleric.hpp character.hpp inventory.hpp
	g++ -c cleric.cpp

goblin.o: goblin.cpp goblin.hpp character.hpp inventory.hpp
	g++ -c goblin.cpp

clean:
	rm *.o Game
