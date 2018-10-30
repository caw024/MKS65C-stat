all: stat.o
	gcc stat.o
run:
	./a.out
stat.o: stat.c
	gcc -c stat.c
clean:
	rm stat.o file.txt
