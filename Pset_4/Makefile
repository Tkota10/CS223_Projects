#
#  Name of File: Makefile
#  Creator: Tarun Kota
#  Class: CPSC 223
#  Date: 04/05/23
#  Purpose: Makefile for the train-conductor.cpp, LinkedList and Station
#


CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra 
DEPS = Station.h LinkedList.h

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

train-conductor: train-conductor.o Station.o LinkedList.o
	$(CXX) -o train-conductor train-conductor.o Station.o LinkedList.o

clean:
	rm -f *.o core* *~ train-conductor
