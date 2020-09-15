exe:main.o gtucontainer.o gtuvector.o gtuset.o
	g++  main.o gtucontainer.o gtuvector.o gtuset.o -o exe

main.o : main.cpp
	g++ -c main.cpp

gtucontainer.o : gtucontainer.cpp gtucontainer.h
	g++ -c gtucontainer.cpp

gtuvector.o:gtuvector.cpp gtuvector.h
	g++ -c   gtuvector.cpp

gtuset.o : gtuset.cpp gtuset.h
	g++ -c gtuset.cpp

clean : 
	rm *.o exe
