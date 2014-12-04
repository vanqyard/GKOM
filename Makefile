all: a.out

a.out: main.o SceneObjects.o
	g++ main.o SceneObjects.o -lGL -lGLU -lglut

main.o: main.cpp SceneObjects.h
	g++ -c main.cpp -o main.o	

SceneObjects.o: SceneObjects.cpp SceneObjects.h
	g++ -c SceneObjects.cpp	-o SceneObjects.o

clean:
	rm a.out
	rm SceneObjects.o
	rm main.o
