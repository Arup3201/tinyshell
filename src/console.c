/*
 * console.c: implements the input interface for user where they can write commands, edit it, go back to one of their previous commands and start executing the command
 *
 * Copyright by Arup J.
 */

#include<stdlib.h>
#include<stdio.h>

#include "console.h"

void initInput(Input *in) {
	in = (Input*)malloc(sizeof(Input));
	in->capacity = INITIAL_INPUT_SIZE;
	in->value = malloc(in->capacity);
	in->size = 0;
}

void appendChar(Input *in, char ch) {
	if(in->size >= in->capacity) {
		int newCap = in->capacity*2;
		in = realloc(in, newCap);
		in->capacity = newCap;
	}

	in->value[in->size] = ch;
	in->size += 1;
}

void read() {
	Input *in;
	initInput(in);

	char ch;
	while(1) {
		ch = fgetc(stdin);	

		if(ch==EOF || ch=='\n') break;
		appendChar(in, ch);
	}

	printf("%s\n", in->value);
	free(in);
}
