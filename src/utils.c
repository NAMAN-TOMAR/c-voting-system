#include <stdio.h>
#include "utils.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard */
    }
}

int readInt() {
    int value;
    int result;

    result = scanf("%d", &value);
    if (result != 1) {
        /* invalid input, clear buffer and set default */
        clearInputBuffer();
        return -1;
    }
    return value;
}

