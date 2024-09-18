#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Function to handle custom delimiter extraction
const char* get_custom_delimiter(const char* input, char* delimiter) {
    if (strncmp(input, "//", 2) == 0) {
        // Find the custom delimiter between "//" and "\n"
        const char* delimiterEnd = strstr(input, "\n");
        if (delimiterEnd != NULL) {
            delimiter[0] = input[2];  // Extract the custom delimiter
            delimiter[1] = '\0';  // Null-terminate the delimiter string
            return delimiterEnd + 1;  // Return pointer to the start of the numbers
        }
    }
    // Use the default delimiter if no custom delimiter is provided
    strcpy(delimiter, ",\n");
    return input;  // Return the original input if no custom delimiter found
}

// Main add function, now simplified
int add(const char* input) {
    int sum = 0;
    char* string = strdup(input);  // Duplicate the input string to modify it
    char delimiter[10];  // Buffer for the delimiter
    const char* numbersStart = get_custom_delimiter(input, delimiter);  // Handle custom delimiter

    char* token;
    /* Tokenize the numbers using the custom or default delimiter */
    token = strtok(string, delimiter);

    /* Walk through the tokens */
    while (token != NULL) {
        int num = atoi(token);  // Convert token to an integer
        if (num <= 1000) {  // Only add numbers <= 1000
            sum += num;
        }
        token = strtok(NULL, delimiter);  // Get the next token
    }

    free(string);  // Free the duplicated string to avoid memory leaks
    return sum;
}


