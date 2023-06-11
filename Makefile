CFLAGS = -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

LFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

win: build
	g++ -o Bullethell.exe olcPixelGameEngine.o main.o game.o entity.o $(CFLAGS)
	./Bullethell.exe

olcPixelGameEngine.o: olcPixelGameEngine.h olcPixelGameEngine.cpp entity.o
	g++ -c olcPixelGameEngine.h olcPixelGameEngine.cpp
main.o: main.cpp olcPixelGameEngine.cpp olcPixelGameEngine.h game.h game.cpp
	g++ -c main.cpp
game.o: olcPixelGameEngine.h olcPixelGameEngine.cpp game.h game.cpp entity.o
	g++ -c game.cpp
entity.o: entity.h entity.cpp
	g++ -c entity.cpp

build: olcPixelGameEngine.o main.o game.o

clean:
	-del *.o
	-rm *.o