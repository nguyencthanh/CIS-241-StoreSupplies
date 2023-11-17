program: project2main.o functions.o
	gcc -o program project2main.o functions.o
	
project2main.o: project2main.c project2.h
	gcc -c project2main.c
	
functions.o: fucntions.c project2.h
	gcc -c functions.c
	
clean:
	rm -f *.o program
