/*
 * console.c: implements the input interface for user where they can write commands, edit it, go back to one of their previous commands and start executing the command
 *
 * Copyright by Arup J.
 */

#include<stdlib.h>
#include<stdio.h>

#include "console.h"

void init_buffer(buffer_ptr *in_ptr) {
	*in_ptr = (buffer_ptr)malloc(sizeof(struct buffer));
	(*in_ptr)->capacity = INITIAL_INPUT_SIZE;
	(*in_ptr)->value = malloc((*in_ptr)->capacity);
	(*in_ptr)->size = 0;
}

void append_char(buffer_ptr *in_ptr, char ch) {
	if((*in_ptr)->size >= (*in_ptr)->capacity) {
		int newCap = (*in_ptr)->capacity*2;
		*in_ptr = realloc(*in_ptr, newCap);
		(*in_ptr)->capacity = newCap;
	}

	(*in_ptr)->value[(*in_ptr)->size] = ch;
	(*in_ptr)->size += 1;
}

void read() {
	buffer_ptr in;
	init_buffer(&in);

	char ch;
	while(1) {
		ch = fgetc(stdin);	
		if(ch=='\n') break;
		
		append_char(&in, ch);
	}
	append_char(&in, '\0');
	printf("%s\n", in->value);

	free(in->value);
	free(in);
}
