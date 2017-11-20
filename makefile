all: pipeit.c
	gcc -o pipeit pipeit.c
run: all
	./pipeit
clean:
	rm *~
