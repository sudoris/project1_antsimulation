output: main.o Board.o Ant.o
	g++ main.o Board.o Ant.o -o output
	
main.o: main.cpp
	g++ -c main.cpp
	
Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

clean: 
	rm *.o output
