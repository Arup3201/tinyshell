// main.c: starting point of the tsh shell

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
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

	// initialize history
	using_history();

	while(1) {
		cmd = readline("$> ");

		if(strlen(cmd) > 0) {
			// add command to history
			add_history(cmd);

			// Parse, expand and execute cmd
			printf("Echo: %s\n", cmd);
		}

		free(cmd);
	}
}
