a.exe: main.o findHole.o
	gcc -o a.exe main.o findHole.o -lstdc++ -std=c++11

main.o : main.cpp findHole.hpp
	gcc -c main.cpp -lstdc++ -std=c++11

findHole.o : findHole.cpp findHole.hpp
	gcc -c findHole.cpp -lstdc++ -std=c++11

run: a.exe
	a.exe