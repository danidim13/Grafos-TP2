CC = g++ -Wall -std=c++11 
inc = -I ./include
src := $(wildcard source/*.cpp)
obj := $(addprefix obj/, $(notdir $(src:.cpp=.o)))

obj/%.o: source/%.cpp include/%.h
	$(CC) $(inc) ${MACROS} -c -o $@ $<

all: $(obj) main.cpp 
	$(CC) $(inc) $^

clean:
	rm -f *.o *.out obj/*.o
