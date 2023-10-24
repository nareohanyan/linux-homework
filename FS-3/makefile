all:
	g++ hacker-rm.o -o hacker-rm
hacker-rm:	hacker-rm.o all clean
hacker-rm.o:	hacker-rm.cpp
	g++ -c hacker-rm.cpp
clean:
	rm *.o
