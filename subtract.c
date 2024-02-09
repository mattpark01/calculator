#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

int main(int argc, char *argv[]) {
    if (argc != 3) { // Check for correct number of arguments
        printf("Error: Two numbers expected\n");
        return 1;
    }

    int result = atoi(argv[1]) - atoi(argv[2]); // atoi converts string to integer and argv is the argument list.
    printf("Result: %d\n", result);
    return 0;
}