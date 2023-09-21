all: output

output: main.o ComplexNumbers.o sortingAlgorithm.o

main.o: main.cpp
	g++ -c main.cpp

ComplexNumbers.o: ComplexNumbers.cpp
	g++ -c ComplexNumbers.cpp
	
sortingAlgorithm.o: sortingAlgorithm.cpp
	g++ -c sortingAlgorithm.cpp
	
clean:
	rm  *.o output
	
