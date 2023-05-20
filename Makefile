all:
	-rm *.o exec
	g++ -c *.cpp
	g++ *.o -o exec