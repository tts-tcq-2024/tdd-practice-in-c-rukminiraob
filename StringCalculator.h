#include <string.h>
#include <stdio.h>
#include <stdlib.h> 

int add(const char*  input)
{
  int sum = 0;
  char*  string = strdup(input);
  const char delimiter[2] = ",\n";
  char* token;
  /* get the first token */
   token = strtok(string, delimiter);
  /* walk through other tokens */
   while( token != NULL ) 
   {
      printf( " %s\n", token );
      sum += atoi(token);
      token = strtok(NULL, delimiter);
   }
  
  return sum;
}
