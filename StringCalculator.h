#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NEGATIVE_NUMBER_ERROR -1

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

// Function to append a negative number to the negatives buffer
void append_negative(char* negatives, int num) {
    char negative[12];
    sprintf(negative, "%d ", num);
    strcat(negatives, negative);
}

// Function to check if a number is negative and process it
void process_negative_token(char* token, char* negatives) {
    int num = atoi(token);
    if (num < 0) {
        append_negative(negatives, num);
    }
}

// Function to check for negative numbers and throw an exception
int check_for_negatives(const char* input, const char* delimiter, char* negatives) {
    char* string = strdup(input);
    char* token = strtok(string, delimiter);
    negatives[0] = '\0';

    while (token) {
        process_negative_token(token, negatives);
        token = strtok(NULL, delimiter);
    }

    free(string);

    if (strlen(negatives) > 0) {
        negatives[strlen(negatives) - 1] = '\0';  // Remove trailing space
        printf("Negatives not allowed: %s\n", negatives);
        return NEGATIVE_NUMBER_ERROR;
    }
    return 0;  // No negatives
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
    char negatives[256];
    const char* numbersStart = get_custom_delimiter(input, delimiter);

    int errorCode = check_for_negatives(numbersStart, delimiter, negatives);
    if (errorCode != 0) {
        return errorCode;
    }
    return sum_numbers(numbersStart, delimiter);
}
