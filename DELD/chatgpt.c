#include <stdio.h>
#include <stdlib.h>

struct in {
    int (*binary)[];
};

int main() {
    struct in *i = malloc(sizeof(struct in));  // Allocate memory for the struct
    if (i == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Allocate memory for an array of 6 integers and assign it to i->binary
    i->binary = malloc(sizeof(int) * 6);
    if (i->binary == NULL) {
        printf("Memory allocation failed\n");
        free(i);
        return 1;
    }

    // Input loop for the array elements
    for (int j = 0; j < 6; j++) {
        printf("Enter integer %d: ", j + 1);
        scanf("%d", &(*i->binary)[j]);
    }

    // Output loop to print array elements
    for (int j = 0; j < 6; j++) {
        printf("%d ", (*i->binary)[j]);
    }
    printf("\n");

    // Free allocated memory
    free(i->binary);
    free(i);

    return 0;
}

