#ifndef CONSOLE_H
#define CONSOLE_H

#define INITIAL_INPUT_SIZE 16

struct Input {
	char *value;
	int size;
	int capacity;
};
typedef struct Input Input;

void read();

#endif
