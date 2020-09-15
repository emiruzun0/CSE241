exe:main.o board.o boardvector.o onedarray.o twodarray.o
	g++  main.o board.o boardvector.o onedarray.o twodarray.o -o exe

main.o : main.cpp
	g++ -c main.cpp

board.o:board.cpp board.h
	g++ -c   board.cpp

boardvector.o : boardvector.cpp boardvector.h
	g++ -c boardvector.cpp

onedarray.o : onedarray.cpp onedarray.h
	g++ -c onedarray.cpp

twodarray.o : twodarray.cpp twodarray.h
	g++ -c twodarray.cpp

clean : 
	rm *.o exe
