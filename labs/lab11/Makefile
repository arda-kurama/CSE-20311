project: cubefunc.o project.o
	gcc cubefunc.o project.o gfx.o -lX11 -lm -o project 

cubefunc.o: cubefunc.c cubefunc.h
	gcc -c cubefunc.c -o cubefunc.o

project.o: project.c cubefunc.h
	gcc -c project.c -o project.o

clean:
	rm project.o
	rm cubefunc.o
	rm project 
