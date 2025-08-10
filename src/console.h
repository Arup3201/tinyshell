#ifndef CONSOLE_H
#define CONSOLE_H

#define CONSOLE_INPUT_INIT_SIZE 16

struct console_input {
	char *value;
	int size;
	int capacity;
};
typedef struct console_input* console_input_ptr;

// initialize and reset the console input
void console_init_input(console_input_ptr *);
void console_reset_input(console_input_ptr *);
void console_free_input(console_input_ptr *);

// set function for console_input_ptr
void console_set_input_value(console_input_ptr *, char);
void console_set_input_size(console_input_ptr *, int);
void console_set_input_capacity(console_input_ptr *, int);

// get functions for console_input_ptr variable
char* console_get_input_value(console_input_ptr); 
int console_get_input_size(console_input_ptr);
int console_get_input_capacity(console_input_ptr);

void console_read_line(console_input_ptr *);

#endif
