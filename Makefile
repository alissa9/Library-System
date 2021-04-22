
GXX = g++

Library:main.o Book.o hash.o
		$(GXX) -Wall main.o Book.o hash.o -o Library
main.o:main.cpp Book.cpp hash.cpp
		$(GXX) -Wall -c main.cpp Book.cpp hash.cpp -g
clean:
	rm *.o Library