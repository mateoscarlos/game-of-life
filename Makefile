life_game: interface.o main.o compute.o
	g++ main.o interface.o compute.o -o life_game

main.o: main.cpp
	g++ -c main.cpp

interfaz.o: interface.cpp
	g++ -c interface.cpp

computo.o: compute.cpp
	g++ -c compute.cpp


.PHONY: clean

clean:
	$(RM) *.o
