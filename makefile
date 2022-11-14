all: main.exe

main.exe: main.o renderWindow.o path.o
	g++ -o main.exe main.o renderWindow.o path.o -L C:/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

main.o: main.cpp include/RenderWindow.hpp include/Path.hpp
	g++ -c main.cpp -I include -I C:\SDL2-w64\include -L C:\SDL2-w64\lib -lmingw32 -lSDL2main -lSDL2

renderWindow.o: renderWindow.cpp include/RenderWindow.hpp
	g++ -c renderWindow.cpp -I include -I C:\SDL2-w64\include -L C:\SDL2-w64\lib -lmingw32 -lSDL2main -lSDL2

path.o: path.cpp include/Path.hpp include/RenderWindow.hpp
	g++ -c path.cpp -I include -I C:\SDL2-w64\include -L C:\SDL2-w64\lib -lmingw32 -lSDL2main -lSDL2