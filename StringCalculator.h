#include <string.h>
#include <stdio.h>
#include <stdlib.h> 

int add(const char*  input)
{
  char*  string = strdup(input);
  const char delimiter[2] = ",";
  char* token;
  
  // get the first token
   token = strtok(string, delimiter);
  // walk through other tokens
  while( token != NULL ) {
    printf( " %s\n", token );
    int num1 = atoi(token);
    token = strtok(NULL, delimiter);
  }
  
  return 0;
}
