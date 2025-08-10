/*
 * console.c: implements the input interface for user where they can write commands, edit it, go back to one of their previous commands and start executing the command
 *
 * Copyright by Arup J.
 */

#include<stdlib.h>
#include<stdio.h>
#include<signal.h>

#include "console.h"

void console_set_input_value(console_input_ptr *, char);
void console_set_input_size(console_input_ptr *, int);
void console_set_input_capacity(console_input_ptr *, int);

void console_init_input(console_input_ptr *in_ptr) {
	*in_ptr = (console_input_ptr)malloc(sizeof(struct console_input));
	console_set_input_capacity(in_ptr, CONSOLE_INPUT_INIT_SIZE);
	(*in_ptr)->value = malloc((*in_ptr)->capacity);
	console_set_input_size(in_ptr, 0);
}

void console_set_input_value(console_input_ptr *in_ptr, char ch) {
	(*in_ptr)->value[(*in_ptr)->size] = ch;
	console_set_input_size(in_ptr, (*in_ptr)->size+1);
}

void console_set_input_size(console_input_ptr *in_ptr, int size) {
	(*in_ptr)->size = size;
}

void console_set_input_capacity(console_input_ptr *in_ptr, int capacity) {
	(*in_ptr)->capacity = capacity;
}

char* console_get_input_value(console_input_ptr in) {
	return in->value;
}

int console_get_input_size(console_input_ptr in) {
	return in->size;
}

int console_get_input_capacity(console_input_ptr in) {
	return in->capacity;
}

void console_append_char_to_input(console_input_ptr *in_ptr, char ch) {
	if(console_get_input_size(*in_ptr) >= console_get_input_capacity(*in_ptr)) {
		int new_cap = console_get_input_capacity(*in_ptr)*2;
		*in_ptr = realloc(*in_ptr, new_cap);
		console_set_input_capacity(in_ptr, new_cap);
	}
	
	console_set_input_value(in_ptr, ch);
}

volatile sig_atomic_t status=0;
void console_catch_terminate_event(int sig) {
	status=sig;
}

int console_read() {
	console_input_ptr in;
	console_init_input(&in);
	
	// handle ctrl+c signal
	if(signal(SIGINT, console_catch_terminate_event) == SIG_ERR) {
		fputs("Error: failed to set signal handler for ctrl+c\n", stdout);
		return EXIT_FAILURE;
	}

	char ch;
	while(1) {
		fputs("tsh > ", stdout);
		while(1) {
			ch = fgetc(stdin);	
			if(ch=='\n') break;

			console_append_char_to_input(&in, ch);
		}
		console_append_char_to_input(&in, '\0');
		
		if(status==SIGINT) {
			fputs("Exiting tsh console\n", stdout);
			free(in->value);
			free(in);
			return EXIT_SUCCESS;
		}
	}	
}
