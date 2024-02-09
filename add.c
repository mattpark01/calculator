#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

int main(int argc, char *argv[]) {
    int sum = 0;
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]); // `argc` is the number of arguments and `argv` is the argument list. It is distinctive by c and v as c represents count and v represents vector.
    }
    printf("Sum: %d\n", sum);
    return 0;
}