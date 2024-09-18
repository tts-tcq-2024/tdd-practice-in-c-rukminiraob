#include <string.h>
#include <stdio.h>
#include <stdlib.h> 

int add(const char*  input)
{
  int sum = 0;
  char*  string = strdup(input);
  char delimiter[10] = ",\n";  // Default delimiters: comma and newline
  char* numbersStart = string;  // Pointer to where the numbers start
  char* token;
  
// Check if the input starts with "//" indicating a custom delimiter
    if (strncmp(string, "//", 2) == 0) {
        // Find the custom delimiter, which is between "//" and "\n"
        char* delimiterEnd = strstr(string, "\n");
        if (delimiterEnd != NULL) {
            // Copy the custom delimiter into the delimiter array
            delimiter[0] = string[2];  // The delimiter is at position 2
            delimiter[1] = '\0';  // Null-terminate the delimiter string
            // Move numbersStart to the part of the string after the "\n"
            numbersStart = delimiterEnd + 1;
        }
    }
    
  /* get the first token */
   token = strtok(string, delimiter);
  /* walk through other tokens */
   while( token != NULL ) 
   {
      int num = atoi(token);  // Convert token to an integer
      if (num <= 1000)
      {
      sum += num;
      }
      token = strtok(NULL, delimiter); // Get the next token
      
   }
  return sum;
}

