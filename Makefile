all: TicTacToe

TicTacToe: board.o game_engine.o listener.o player.o point.o renderer.o main.o
	g++ -o TicTacToe.exe board.o game_engine.o listener.o player.o point.o renderer.o main.o

board.o:
	g++ board.cpp -o board.o -c

game_engine.o:
	g++ game_engine.cpp -o game_engine.o -c

listener.o:
	g++ listener.cpp -o listener.o -c

player.o:
	g++ player.cpp -o player.o -c

point.o:
	g++ point.cpp -o point.o -c

renderer.o:
	g++ renderer.cpp -o renderer.o -c

main.o:
	g++ main.cpp -o main.o -c

clean:
	rm -f *.o *.exe