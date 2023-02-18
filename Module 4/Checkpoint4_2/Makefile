# Answer to Checkpoint 4.2
FLAGS = -pedantic-errors -std=c++11

calc: 
	g++ $(FLAGS) -c calc.cpp 
	g++ $(FLAGS) -c lcm.cpp
	g++ $(FLAGS) -c gcd.cpp
	g++ $(FLAGS) -o calc calc.o lcm.o gcd.o 
	rm -f *.o # optional

clean:
	rm -f calc *.o

.PHONY: clean


