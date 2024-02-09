#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h> // for PATH_MAX

void execute_command(const char *cmd, char **args) {
    int pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(cmd, args) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE); // Exit child process if exec fails
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for the child process to finish
    } else {
        // Forking failed
        perror("fork");
    }
}

int main() {
    char input[256];
    char *args[10];
    char cmd[PATH_MAX];

    while (1) {
        printf("Calculator> ");
        // `fgets` reads a line from the specified stream and stores it into the string pointed to by `input`.
        // `stdin` is the standard input stream.
        // `sizeof(input)` is the maximum number of characters to be read.
        // `fgets` returns `NULL` on error or when end of file occurs while no character has been read.
        // To summarize, this line reads a line from the user and stores it in `input`.
        if (!fgets(input, sizeof(input), stdin)) {
            printf("\nExiting calculator shell\n");
            break; // Exit if we can't get the current directory.
        }

        // Parse the command and arguments
        // `char *token` is a pointer to the first token found in `input`.
        // `strtok` is a function that finds the next token in a string.
        // `input` is the string to be broken into tokens.
        // To summarize, this line gets the first token from `input`.
        char *token = strtok(input, " \n");
        
        int i = 0;

        while (token != NULL) {
            // `args[i]` is the `i`th element of the `args` array.
            // `args` comes from the `main` function and is an array of strings.
            // We know `args` is an array of strings and not a pointer to a string because it is declared as `char *args[10]` and not `char **args`.
            // The difference between `*args[10]` and `**args` is that the former is an array of pointers to strings as denoted by the `*` symbol and
            // the latter is a pointer to a pointer to a string as denoted by the `**` symbol. A pointer to a pointer to a string means that the pointer
            // points to a pointer that points to a string. An array of pointers to strings means that the array contains pointers that point to strings.
            args[i] = token; // Store the argument
            if (i == 0) { // First token is the command
                // Construct the full path for the command based on the first token
                // Use `snprintf` to avoid buffer overflow
                // A buffer is a temporary storage area that stores data while it is being processed.
                // Overflow is when a program writes more data to a buffer than it can hold.
                // Therefore buffer overflow is when a program writes more data to a buffer than it can hold.
                // In summary `snprinf` is a function that writes formatted data to a string with a specified maximum length of characters.
                // The maximum length of characters is specified by the `PATH_MAX` constant.
                // The `PATH_MAX` constant is the maximum length of a file name string.
                snprintf(cmd, PATH_MAX, "%s/%s", cwd, token);
                i++; // Move to the next argument.
                // `strtok` is a function that finds the next token in a string.
                // For this particular program `strtok` is used to find the next token in the `input` string.
                token = strtok(NULL, " \n");
            }
            // NULL-terminate the argument list.
            // NULL-terminate means to add a NULL CHARACTER to the end of a string.
            // A NULL CHARACTER is a character with all bits set to zero.
            // When all bits are set to zero the character is visualized as nothing.
            // For this particular program we NULL-terminate the argument list to indicate the end of the list.
            args[i] = strtok(NULL, " \n");

            printf("Executing the commannd: $s\n", cmd);
            // This loop prints the arguments.
            for (int j = 0; j < i; j++) {
                printf("arg[%d]: %s\n", j, args[j]);
            }

            // Once the user enters the command, the program will execute the command.
            execute_command(cmd, args);
        }
    }
}