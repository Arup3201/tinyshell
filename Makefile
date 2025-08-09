CFLAGS = -Wall

tsh.out: main.c src/console.c src/console.h
	gcc -c src/console.c -o builds/console.out
	gcc main.c -o tsh.out builds/*.out

debug: 
	gcc -c src/console.c -g -o builds/console.out
	gcc main.c -g -o tsh.out builds/*.out

clean:
	rm -rf tsh.out builds/*.out
