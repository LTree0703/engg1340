# Answer to Checkpoint 4.2
FLAGS = -pedantic-errors -std=c++11

calc: calc.o gcd.o lcm.o
	g++ $(FLAG) $^ -o $@

calc.o: calc.cpp gcd.h lcm.h
	g++ $(FLAG) -c $<

lcm.o: lcm.cpp lcm.h gcd.h
	g++ $(FLAG) -c $<

gcd.o: gcd.cpp gcd.h
	g++ $(FLAG) -c $<

clean:
	rm -f calc *.o

.PHONY: clean


