Puzzle.exe: Tile.o TileManager.o Puzzle.o
	g++ Tile.o TileManager.o Puzzle.o -o Puzzle.exe

Tile.o: Tile.cpp
	g++ -c Tile.cpp -o Tile.o
	
TileManager.o: TileManager.cpp
	g++ -c TileManager.cpp -o TileManager.o

Puzzle.o: Puzzle.cpp
	g++ -c Puzzle.cpp -o Puzzle.o

clean:
	rm -f *.o Puzzle.exe *.pgm