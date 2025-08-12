// main.c: starting point of the tsh shell

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<readline/readline.h>
#include<readline/history.h>

void terminate_signal_handler(int signo) {
	rl_clear_signals();
	printf("\nExiting tinyshell...\n");
	exit(EXIT_SUCCESS);
}

int main() {
	char *cmd;

	// attach signal handler
	if(signal(SIGINT, terminate_signal_handler) == SIG_ERR) {
		fputs("error while attaching signal handler\n", stderr);
		return 1;
	}

	while(1) {
		cmd = readline("$> ");
		
		// Parse, expand and execute cmd
		printf("Echo: %s\n", cmd);

		free(cmd);
	}
}
