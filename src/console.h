#ifndef CONSOLE_H
#define CONSOLE_H

#define INITIAL_INPUT_SIZE 16

struct buffer {
	char *value;
	int size;
	int capacity;
};
typedef struct buffer* buffer_ptr;

void read();

#endif
