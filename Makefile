CC = g++ -Wall -std=c++11 
inc = -I ./include
src := $(wildcard source/*.cpp)
obj := $(addprefix obj/, $(notdir $(src:.cpp=.o)))

obj/%.o: source/%.cpp include/%.h
	$(CC) $(inc) ${MACROS} -c -o $@ $<

main.out: $(obj) main.cpp 
	$(CC) $(inc) $^ -o $@

test.out: $(obj) test.cpp 
	$(CC) $(inc) $^ -o $@

dic.out: $(obj) mainDicc.cpp
	$(CC) $(inc) $^ -o $@

all: main.out dic.out

clean:
	rm -f *.o *.out obj/*.o
