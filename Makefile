DebugFlag = -g -Wl,--stack,4194304
ObjectFiles = main.o Cube.o Kabina.o Wspornik.o Skybox.o SegmentWiezy.o Blok.o Wieza.o Sfera.o PodstawaDzwigu.o Walec.o TylneRamie.o Rifle.o PrzednieRamie.o
Compile = g++
Libraries = -lm -lGL -lGLU -lSOIL -std=c++0x -lSDL -lSDL2 -lSDL2_ttf -lSDL2_image

a.out: $(ObjectFiles)
	$(Compile) -o a.out  main.o  Cube.o  Kabina.o  Wspornik.o  Skybox.o  SegmentWiezy.o  Blok.o  Wieza.o  Sfera.o  PodstawaDzwigu.o  Walec.o  TylneRamie.o  Rifle.o  PrzednieRamie.o $(Libraries)

main.o: main.cc  SceneObjects.h
	$(Compile) -c main.cc -o  main.o $(DebugFlag) $(Libraries)

Cube.o:  Cube.cc  SceneObjects.h
	$(Compile) -c  Cube.cc -o  Cube.o $(DebugFlag) $(Libraries)

Kabina.o:  Kabina.cc  SceneObjects.h
	$(Compile) -c  Kabina.cc -o  Kabina.o $(DebugFlag) $(Libraries)

Wspornik.o:  Wspornik.cc  SceneObjects.h
	$(Compile) -c  Wspornik.cc -o  Wspornik.o $(DebugFlag) $(Libraries)

Skybox.o:  Skybox.cc  SceneObjects.h
	$(Compile) -c  Skybox.cc -o  Skybox.o $(DebugFlag) $(Libraries)
	
SegmentWiezy.o:  SegmentWiezy.cc  SceneObjects.h
	$(Compile) -c  SegmentWiezy.cc -o  SegmentWiezy.o $(DebugFlag) $(Libraries)
	
Blok.o:  Blok.cc  SceneObjects.h
	$(Compile) -c  Blok.cc -o  Blok.o $(DebugFlag) $(Libraries)

Wieza.o:  Wieza.cc  SceneObjects.h
	$(Compile) -c  Wieza.cc -o  Wieza.o $(DebugFlag) $(Libraries)

Sfera.o:  Sfera.cc  SceneObjects.h
	$(Compile) -c  Sfera.cc -o  Sfera.o $(DebugFlag) $(Libraries)
	
PodstawaDzwigu.o:  PodstawaDzwigu.cc  SceneObjects.h
	$(Compile) -c  PodstawaDzwigu.cc -o  PodstawaDzwigu.o $(DebugFlag) $(Libraries)

Walec.o:  Walec.cc  SceneObjects.h
	$(Compile) -c  Walec.cc -o  Walec.o $(DebugFlag) $(Libraries)
		
TylneRamie.o:  TylneRamie.cc  SceneObjects.h
	$(Compile) -c  TylneRamie.cc -o  TylneRamie.o $(DebugFlag) $(Libraries)

PrzednieRamie.o:  PrzednieRamie.cc  SceneObjects.h
	$(Compile) -c  PrzednieRamie.cc -o  PrzednieRamie.o $(DebugFlag) $(Libraries)
		
Rifle.o:  Rifle.cc  SceneObjects.h
	$(Compile) -c  Rifle.cc -o  Rifle.o $(DebugFlag) $(Libraries)
	
clean:
	rm a.out
	rm  *.o 
