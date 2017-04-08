a.exe: main.o
	gcc -o a.exe main.o -lstdc++ -std=c++11

main.o : main.cpp findHole.hpp
	gcc -c main.cpp -lstdc++ -std=c++11

run: a.exe
	a.exe