Dungeon: Dragon.o Entity.o Fighter.o Game.o Goblin.o Monster.o Player.o Room.o Sorcerer.o invalidRoom.o main.o
	g++ Dragon.o Entity.o Fighter.o Game.o Goblin.o Monster.o Player.o Room.o Sorcerer.o invalidRoom.o main.o -o Dungeon

Dragon.o: Dragon.cpp Dragon.h Monster.h Entity.h Player.h
	g++ -c Dragon.cpp

Entity.o: Entity.cpp Entity.h
	g++ -c Entity.cpp
Fighter.o: Fighter.cpp Fighter.h Player.h Entity.h Monster.h
	g++ -c Fighter.cpp

Game.o: Game.cpp Game.h Room.h Entity.h Monster.h Player.h Fighter.h \
Sorcerer.h invalidRoom.h
	g++ -c Game.cpp
Goblin.o: Goblin.cpp Goblin.h Monster.h Entity.h Fighter.h Player.h
	g++ -c Goblin.cpp
Monster.o: Monster.cpp Monster.h Entity.h Fighter.h Player.h
	g++ -c Monster.cpp
Player.o: Player.cpp Player.h Entity.h
	g++ -c Player.cpp
Room.o: Room.cpp Room.h Entity.h Monster.h Dragon.h Goblin.h
	g++ -c Room.cpp
Sorcerer.o: Sorcerer.cpp Sorcerer.h Player.h Entity.h Monster.h
	g++ -c Sorcerer.cpp
invalidRoom.o: invalidRoom.cpp invalidRoom.h
	g++ -c invalidRoom.cpp
main.o: main.cpp Game.h Room.h Entity.h Monster.h Player.h
	g++ -c main.cpp

clean:
	rm -f *.o Dungeon *.gch