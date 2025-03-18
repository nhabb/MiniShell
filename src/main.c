#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_ARGS 100
#define DELIM " \t\r\n\a"  // Define delimiters (space, tab, newline)

void tokenize_input(char *input) {
    char *tokens[MAX_ARGS];  // Array to store tokens
    int i = 0;
    char *token = input;
    while (*token != '\0') {
        while (*token && strchr(DELIM, *token)) {
            token++;
        }
        if (*token) {
            tokens[i++] = token;
            // Find the end of the token (next delimiter or end of string)
            while (*token && !strchr(DELIM, *token)) {
                token++;
            }
            // Null-terminate the token
            if (*token != '\0') {
                *token = '\0';
                token++;  // Move past the delimiter
            }
        }
    }
    tokens[i] = NULL;
    printf("Tokens:\n");
    for (int j = 0; j < i; j++) {
        printf("  [%s]\n", tokens[j]);
    }
}

int main() {
    char *input;

    while (1) {
        input = readline("minishell>$ ");  
        if (!input) break;  // Handle Ctrl+D
        if (*input) add_history(input);  
        tokenize_input(input);  // Tokenize the input
        free(input);  
    }
    return 0;
}
