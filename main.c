// main.c: starting point of the tsh shell

#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<readline/readline.h>
#include<readline/history.h>

volatile sig_atomic_t status = 0;
void set_status(int sig) {
	status = sig;
}

int main() {
	char *cmd;

	if(signal(SIGINT, set_status) == SIG_ERR) {
		fputs("error handling signal", stderr);
		return 1;
	}

	while(1) {
		if(status == SIGINT) {
			free(cmd);
			printf("exiting tinyshell\n");
			return 0;
		}
		
		cmd = readline("$> ");
		
		// Parse, expand and execute cmd
		printf("Echo: %s\n", cmd);
	}
}
