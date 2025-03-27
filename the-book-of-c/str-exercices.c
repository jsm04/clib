#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlen_impl(char *str) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

void strcpy_custom_impl(char *destination, char *source, size_t size) {
    int i = 0;
    while (i < size && source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

// Write a program that asks for a string from a user and "strips" all
// whitespace characters from the end of the string (spaces, tabs and newlines).
// To do that, you can simply assign a null character to the character array
// index that follows the last non-whitespace character of the string.
void remove_trailing_space(char *str) {
    int i = 0;
    int last_non_space_char = -1;

    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            last_non_space_char = i;
        }
        i++;
    }

    if (last_non_space_char != -1) {
        str[last_non_space_char + 1] = '\0';
    }
}

int main(void) {
    //    char str[] = "Hello world";
    //    // Calculate array length without strlen.
    //    int len = strlen_impl(str);
    //
    //    for (int i = 0; i <= len; i++) {
    //        printf("%d index, %d array\n", i, str[i]);
    //    }
    //
    //    char str_copy[len];
    //    strcpy_custom_impl(str_copy, str, len);
    //    printf("%s <-- this is the str copy", str_copy);

    char str_buff[127];
    fgets(str_buff, sizeof(str_buff), stdin);
    remove_trailing_space(str_buff);
    printf("%s <--- string without trailing space.", str_buff);

    return EXIT_SUCCESS;
}
