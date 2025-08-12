CFLAGS = -Wall -o
DEBUGFLAGS = -Wall -g -o
LIBS = -lreadline

tsh.out: main.c
	gcc main.c $(LIBS) $(CFLAGS) tsh.out

debug: 
	gcc main.c $(LIBS) $(DEBUGFLAGS) tsh.out

