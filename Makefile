all: board.o square.o coordinates.o exeptions.o

board.o: Board.cpp
	clang++ -c -std=c++11  Board.cpp

square.o: square.cpp
	clang++ -c -std=c++11 square.cpp

coordinates.o: coordinates.cpp
	clang++ -c -std=c++11 coordinates.cpp

exeptions.o: exeptions.cpp
	clang++ -c -std=c++11 exeptions.cpp

clean:
	rm -rf *.o hello
