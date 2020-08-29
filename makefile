EXE = bin/StackTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

all:$(EXE)
.PHONY: all run test memcheck clean

run:$(EXE)
	@echo "Press enter to run the test driver"
	@read DUMMY
	@-$(EXE)
	@echo "Press enter to memcheck the test driver"
	@read DUMMY
	$(MEMCHECK) $(EXE)

test: $(EXE)
	$(EXE)

memcheck: $(EXE)
	$(MEMCHECK) $(EXE)

clean:
	mkdir -p obj
	mkdir -p bin
	rm obj/*
	rm bin/*
	rmdir obj
	rmdir bin

$(EXE):obj/StackTest.o obj/ParenthesesMatch.o
	mkdir -p bin
	$(CC) $(OPTIONS) $(DEBUG) -o $(EXE) obj/StackTest.o obj/ParenthesesMatch.o

obj/StackTest.o:src/StackTest.cpp inc/Stack.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/StackTest.o -c  -I inc/ src/StackTest.cpp

obj/ParenthesesMatch.o:src/ParenthesesMatch.cpp inc/ParenthesesMatch.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/ParenthesesMatch.o -c  -I inc/ src/ParenthesesMatch.cpp
