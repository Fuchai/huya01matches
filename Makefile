mygrep: lookInFile.o mygrep.o
	gcc -o mygrep lookInFile.o mygrep.o
lookInFile.o: lookInFile.c lookInFile.h
	gcc -c lookInFile.c
mygrep.o: mygrep.c
	gcc -c mygrep.c
clean:
	rm *.o
	rm count