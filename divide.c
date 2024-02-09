#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Two numbers expected\n");
        return 1;
    }

    int divisor = atoi(argv[2]);
    if (divisor == 0) {
        printf("Error: Division by zero\n");
        return 1;
    }

    int quotient = atoi(argv[1]) / divisor;
    printf("Quotient: %d\n", quotient);
    return 0;
}
