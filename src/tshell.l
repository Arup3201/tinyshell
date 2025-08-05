/*
 * tshell.l: simple lexical analyzer for the tiny shell.
 */

%%
"\n" {
	return NEWLINE;
}
[ \t ] {
	/* Discard spaces and tabs */
}
">" {
	return GREAT;
}
"<" {
	return LESS;
}
">>" {
	return GREATGREAT;
}
">&" {
	return GREATAMPERSAND;
}
"&" {
	return AMPERSAND;
}
"|" {
	return PIPE;
}
[^ \t\n ] [^ \t\n]* {
	yylval.string_val = strdup(yytext);
	return WORD;
}
{
	return NOTOKEN;
}
%%
