# tinyshell
Simple shell implementation in C

## features

1. Pipeline: Multiple commands chained together by their standard streams, so that output text of each process (`stdout`) is passed directly as input (`stdin`) to the next one. Read more from [wiki](https://en.wikipedia.org/wiki/Pipeline_(Unix)). The syntax is to list multiple commands, separated by vertical bars (pipes - "|").
2. Filename wildcard: Match file names using wildcard characters. Supported wildcard characters are `*`, `?`, `[]`, `!`. Read more from [wiki](https://en.wikipedia.org/wiki/Wildcard_character).
3. Command substitution: Run a command and paste the output of that command on the command line to another command. `vi $(fgrep -l malloc *.c)` will find all the `C` files that has `malloc` in it and then open them with `vi` editor. Learn more from [wiki](https://en.wikipedia.org/wiki/Command_substitution).
4. Shell variables: 
5. User-executable shell script:
6. Interrupt handling: 
7. Control structures: if/then/else/endif, switch/breaksw/endsw and while/end/break/continue
