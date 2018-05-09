CXX=clang++-5.0
CPPFLAGS=-std=c++17 

all: Board.o square.o coordinates.o exeptions.o

Board.o: Board.cpp Board.h
	$(CXX) $(CPPFLAGS) --compile  Board.cpp -o Board.o

square.o: square.cpp
	$(CXX) $(CPPFLAGS) --compile square.cpp -o square.o

coordinates.o: coordinates.cpp
	$(CXX) $(CPPFLAGS) --compile coordinates.cpp -o coordinates.o

exeptions.o: exeptions.cpp
	$(CXX) $(CPPFLAGS) --compile exeptions.cpp -o exeptions.o

clean:
	rm -rf *.o hello
