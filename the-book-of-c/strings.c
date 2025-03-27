#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[128];

    printf("Gimme a string: ");
    fgets(buffer, 128, stdin);

    size_t size =
        strlen(buffer) + 1;  // add 1 for the null termination character!

    // Creates a buffer array of n size to then pass the value in strcpy.
    char copy_buffer[size];
    strlcpy(copy_buffer, buffer, size);

    return EXIT_SUCCESS;
}
