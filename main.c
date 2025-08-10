// main.c: starting point of the tsh shell

#include<signal.h>
#include<stdlib.h>
#include<stdio.h>

#include "src/console.h"

volatile sig_atomic_t status=0;
void catch_terminate_event(int sig) {
	status=sig;
}

int main() {
	console_input_ptr in;
	console_init_input(&in);

	// handle ctrl+c signal
	if(signal(SIGINT, catch_terminate_event) == SIG_ERR) {
		fputs("Error: failed to set signal handler for ctrl+c\n", stdout);
		return EXIT_FAILURE;
	}

	while(1) {
		// read one line
		console_read_line(&in);

		// code to execute the line
		printf("Echo: %s\n", in->value);

		// clean up the console
		console_reset_input(&in);

		if(status==SIGINT) {
			fputs("Exiting tsh console\n", stdout);
			console_free_input(&in);
			return EXIT_SUCCESS;
		}
	}
}
