#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"

void read_and_print_input(void) {
    int character;

    while ((character = getchar()) != EOF) {
        character != '\n' && printf("You inputed: ");
        putchar(character);
        printf("\n");
    }
}

// Exercise 1
void read_and_print_input_with_fgets(void) {
    int buff_len = 64;
    char char_buffer[buff_len];

    printf("Enter a line: ");

    while (fgets(char_buffer, buff_len, stdin)) {
        puts(char_buffer);
    }
}

// Exercise 2
void print_char_with_message(int *c) {
    if (*c != '\n') {
        printf("You inputed: ");
    }
    putchar(*c);
    printf("\n");
}

void read_and_print_input_as_uppercase(void) {
    int character;

    while ((character = getchar()) != EOF) {
        if (islower(character)) {
            int upper = toupper(character);
            print_char_with_message(&upper);
        } else {
            print_char_with_message(&character);
        }
    }
}

// Exercise 3
void dog_name_and_age_in_human_years(void) {
    char name[100];
    int age_in_human_years;
    int age_in_dog_years;

    printf("Enter your dog's name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter %s age in human years: ", name);
    scanf("%d", &age_in_human_years);

    age_in_dog_years = age_in_human_years * 7;

    printf("%s is %d years old in dog years.\n", name, age_in_dog_years);
}

int main(void) {
    void (*fn_ptr[])(void) = {
        read_and_print_input, read_and_print_input_with_fgets,
        read_and_print_input_as_uppercase, dog_name_and_age_in_human_years};

    int choice;

    printf("Choose an option:\n");
    printf("1. Read and print input\n");
    printf("2. Read and print with fgets\n");
    printf("3. Read and print input as uppercase\n");
    printf("4. Dog name and age in human years\n");
    printf("Enter your choice (1-4): ");

    scanf("%d", &choice);  // Read user's choice
    getchar();             // To consume the newline character left by scanf

    if (choice >= 1 && choice <= 4) {
        fn_ptr[choice - 1]();  
    } else {
        printf("Invalid choice\n");
    }
    return EXIT_SUCCESS;
}
