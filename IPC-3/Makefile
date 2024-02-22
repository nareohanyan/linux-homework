all: shared_array

shared_array: first.o second.o shared_array.o

first.o: first.cpp
	g++ -c first.cpp

second.o: second.cpp
	g++ -c second.cpp

shared_array.o: shared_array.cpp
	g++ -c shared_array.o

clean:
	rm *.o all

	
