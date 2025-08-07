# tinyshell
Simple shell implementation in C

## features

- Command interpreter: Allow execution of UNIX commands both synchronously and asynchronously. It allows control over the contents of the environment. It works interactively or non-interactively. It can accept input from keyboard or from a file.
- Commands: Support commands like `cd`, `pwd`.
- Programming language: It works as a programming language which supports variables, flow control, functions and quoting.
- Interactive: It supports job control, command line editing, history and aliases. Job control allows user to suspend or restart a job. Aliases will allow strings to be substituted by commands, it helps in shortening lengthy commands or making sure a command is executed with some basic set of options.
- Pipeline: Multiple commands chained together by their standard streams, so that output text of each process (`stdout`) is passed directly as input (`stdin`) to the next one. Read more from [wiki](https://en.wikipedia.org/wiki/Pipeline_(Unix)). The syntax is to list multiple commands, separated by vertical bars (pipes - "|").
- Filename wildcard: Match file names using wildcard characters. Supported wildcard characters are `*`, `?`, `[]`, `!`. Read more from [wiki](https://en.wikipedia.org/wiki/Wildcard_character).
- Command substitution: Run a command and paste the output of that command on the command line to another command. `vi $(fgrep -l malloc *.c)` will find all the `C` files that has `malloc` in it and then open them with `vi` editor. Learn more from [wiki](https://en.wikipedia.org/wiki/Command_substitution).
