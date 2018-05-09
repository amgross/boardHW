all: a.out

a.out: main.cpp board.cpp square.cpp coordinates.cpp exeptions.o
	clang++ main.cpp board.cpp square.cpp coordinates.cpp exeptions.cpp -std=c++11 -o a.out
	
clean:
	rm -rf *.o a.out
