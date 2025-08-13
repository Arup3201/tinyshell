/*
 * lexer.c: Perform lexical analysis on the input by breaking the input into units ("token") that has meaning with respect to the shell programming language
 *
 */

#include "lexer.h"

int automata[NUM_STATES][NUM_ASCII_CHARS];

void init_automata() {
	for(int i=0; i<NUM_STATES; i++) {
		for(int j=0; j<NUM_ASCII_CHARS; j++) {
			automata[i][j] = 0;
		}
	}
}

// ASCII values - https://www.ascii-code.com/
void set_automata() {
}
