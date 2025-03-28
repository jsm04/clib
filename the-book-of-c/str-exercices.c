#include <ctype.h>
#include <stddef.h>
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

// Write a program that asks for a string from a user and prints the string in
// reverse.
void print_str_in_reverse(size_t buff_size) {
    char buff[buff_size];

    fgets(buff, buff_size, stdin);

    size_t len = 0;

    while (buff[len] != '\0' && buff[len] != '\n') len++;

    if (buff[len] == '\n') {
        buff[len] = '\0';
    }

    for (int i = len - 1; i >= 0; i--) {
        printf("%c", buff[i]);
    }

    printf("\n");
}
// Write a program that asks for a string from a user and prints whether the
// string is a palindrome. Don't implement this problem recursively; check the
// characters within the string in some type of loop structure. In your
// implementation, ignore non-letters and treating the string in a
// case-insensitive manner. For example, "A man, a plan, a canal, Panama!"
// should be considered a valid palindrome.
int is_palindrome(char *str) {
    int start = 0;
    int end = 0;

    while (str[end] != '\0') end++;
    end--;

    while (start < end) {
        if (!isalnum(str[start])) {
            start++;
            continue;
        }

        if (!isalnum(str[end])) {
            end--;
            continue;
        }

        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}

int main(void) {
    /*
    // Calculate array length without strlen.
    char str[] = "Hello world";
    int len = strlen_impl(str);

    for (int i = 0; i <= len; i++) {
        printf("%d index, %d array\n", i, str[i]);
    }

    // Strcpy copy impl
    char str_copy[len];
    strcpy_custom_impl(str_copy, str, len);
    printf("%s <-- this is the str copy", str_copy);

    // Remove trailing space
    char str_buff[127];
    fgets(str_buff, sizeof(str_buff), stdin);
    remove_trailing_space(str_buff);
    printf("%s <--- string without trailing space.", str_buff);
    */

    /*print_str_in_reverse(32);*/

    // Check if palindrome
    char palindrome[] = "A man, a plan, a canal, Panama";
    int is_p = is_palindrome(palindrome);
    printf("%d.", is_p);  

    return EXIT_SUCCESS;
}
