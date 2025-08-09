/*
 * console.c: implements the input interface for user where they can write commands, edit it, go back to one of their previous commands and start executing the command
 *
 * Copyright by Arup J.
 */

#include<stdlib.h>
#include<stdio.h>

#include "console.h"

void init_buffer(buffer_ptr in) {
	in = (buffer_ptr)malloc(sizeof(struct buffer));
	in->capacity = INITIAL_INPUT_SIZE;
	in->value = malloc(in->capacity);
	in->size = 0;
}

void append_char(buffer_ptr in, char ch) {
	if(in->size >= in->capacity) {
		int newCap = in->capacity*2;
		in = realloc(in, newCap);
		in->capacity = newCap;
	}

	in->value[in->size] = ch;
	in->size += 1;
}

void read() {
	buffer_ptr in;
	init_buffer(in);

	char ch;
	while(1) {
		ch = fgetc(stdin);	

		if(ch==EOF || ch=='\n') break;
		append_char(in, ch);
	}

	printf("%s\n", in->value);
	free(in);
}
