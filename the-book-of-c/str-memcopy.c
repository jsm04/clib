#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[128];
    printf("Gimme a string: ");
    fgets(buffer, 128, stdin);
    size_t size =
        strlen(buffer) + 1;  // add 1 for the null termination character!
    char copy[size];
    strlcpy(copy, buffer, size);
    return EXIT_SUCCESS;
}
