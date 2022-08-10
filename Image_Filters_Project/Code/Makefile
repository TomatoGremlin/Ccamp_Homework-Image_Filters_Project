build: my_filter.c my_filter.h main.c
	mkdir my_filter
	gcc -c my_filter.c
	gcc -c main.c
	gcc my_filter.o main.o -o projectExe
	mv my_filter.o main.o projectExe ./my_filter
clean:
	rm -r ./my_filter
