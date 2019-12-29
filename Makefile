all: clean interface application

interface:
	g++ -static -c ThreadMap/threadMap.cpp API/api.cpp -std=c++17
	ar rcs libinterface.a threadMap.o api.o

application:
	gcc -c main.c
	gcc -Wall -Wextra main.o libinterface.a -o app -lstdc++

clean:
	rm -rf *.a *.o app
