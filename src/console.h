#ifndef CONSOLE_H
#define CONSOLE_H

#define CONSOLE_INPUT_INIT_SIZE 16

struct console_input {
	char *value;
	int size;
	int capacity;
};
typedef struct console_input* console_input_ptr;

char* console_get_input_value(console_input_ptr); 
int console_get_input_size(console_input_ptr);
int console_get_input_capacity(console_input_ptr);

int console_read();

#endif
