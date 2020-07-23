CC=g++
CFLAGS=-std=c++11
SOURCES=main.cpp layer.cpp neuron.cpp part_1.cpp part_2.cpp
DEPS=ann.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ann

all:$(EXECUTABLE)
	@echo Make has finished.

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp

clean:
	$(RM) *.o *~$(EXECUTABLE)
