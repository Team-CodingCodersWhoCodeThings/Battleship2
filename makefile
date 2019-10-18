Battleship: main.o exec.o Player.o easyAI.o mediumAI.o hardAI.o
	g++ -g -std=c++11 -Wall main.o exec.o Player.o easyAI.o mediumAI.o hardAI.o -o Battleship

main.o: main.cpp exec.h 
	g++ -g -std=c++11 -Wall -c main.cpp

exec.o: exec.h exec.cpp Player.h easyAI.h mediumAI.h hardAI.h
	g++ -g -std=c++11 -Wall -c exec.cpp

Player.o: Player.h Player.cpp
	g++ -g -std=c++11 -Wall -c Player.cpp

easyAI.o: easyAI.h easyAI.cpp
	g++ -g -std=c++11 -Wall -c easyAI.cpp

mediumAI.o: mediumAI.h mediumAI.cpp
	g++ -g -std=c++11 -Wall -c mediumAI.cpp

hardAI.o: hardAI.h hardAI.cpp
	g++ -g -std=c++11 -Wall -c hardAI.cpp

clean:
	rm *.o Battleship
