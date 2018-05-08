all: hello

hello: main.o board.o square.o coordinates.o exeptions.o
	clang++ main.o board.o square.o coordinates.o exeptions.o -std=c++11 -o hello

main.o:  main.cpp
	clang++ -c -std=c++11 main.cpp

board.o: board.cpp
	clang++ -c -std=c++11  board.cpp

square.o: square.cpp
	clang++ -c -std=c++11 square.cpp

coordinates.o: coordinates.cpp
	clang++ -c -std=c++11 coordinates.cpp

exeptions.o: exeptions.cpp
	clang++ -c -std=c++11 exeptions.cpp

clean:
	rm -rf *.o hello