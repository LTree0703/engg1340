main2: main2.cpp searchword.o
	g++ -pedantic-errors -std=c++11 main2.cpp searchword.o -o main2

searchword.o: searchword.cpp searchword.h
	g++ -pedantic-errors -std=c++11 -c searchword.cpp -o searchword.o

clean:
	rm -rf output/ *.o main2