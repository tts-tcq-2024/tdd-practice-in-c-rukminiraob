#include <string.h>
#include <stdio.h>
#include <stdlib.h> 

int add(const char*  input)
{
  int sum = 0;
  char*  string = strdup(input);
  static char delimiter[] = ",\n";
  char* token;
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
