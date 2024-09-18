#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Function to handle custom delimiter extraction
const char* get_custom_delimiter(const char* input, char* delimiter) {
    if (strncmp(input, "//", 2) == 0) {
        const char* delimiterEnd = strstr(input, "\n");
        if (delimiterEnd != NULL) {
            delimiter[0] = input[2];
            delimiter[1] = '\0';
            return delimiterEnd + 1;
        }
    }
    strcpy(delimiter, ",\n");
    return input;
}

// Function to check for negative numbers and throw an exception
void check_for_negatives(const char* input, const char* delimiter) {
    char* string = strdup(input);
    char* token = strtok(string, delimiter);
    char negatives[256] = "";

    while (token) {
        int num = atoi(token);
        if (num < 0) {
            char negative[12];
            sprintf(negative, "%d ", num);
            strcat(negatives, negative);
        }
        token = strtok(NULL, delimiter);
    }

    free(string);

    if (strlen(negatives) > 0) {
        negatives[strlen(negatives) - 1] = '\0';
        printf("Negatives not allowed: %s\n", negatives);
        exit(1);
    }
}

// Function to tokenize and sum numbers
int sum_numbers(const char* input, const char* delimiter) {
    int sum = 0;
    char* string = strdup(input);
    char* token = strtok(string, delimiter);

    while (token) {
        int num = atoi(token);
        if (num <= 1000) {
            sum += num;
        }
        token = strtok(NULL, delimiter);
    }

    free(string);
    return sum;
}

// Main add function
int add(const char* input) {
    char delimiter[10];
    const char* numbersStart = get_custom_delimiter(input, delimiter);
    check_for_negatives(numbersStart, delimiter);
    return sum_numbers(numbersStart, delimiter);
}
