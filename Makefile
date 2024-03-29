all: clean interface application

interface:
	g++ -g -static -c Map.cpp doublyLinkedList.cpp api.cpp -std=c++17
	ar rcs libinterface.a Map.o doublyLinkedList.o api.o

application:
	gcc -c -g main.c test_map_benchmark.c
	gcc -Wall -Wextra -g main.o test_map_benchmark.o libinterface.a -o app -lstdc++

clean:
	rm -rf *.a *.o app
