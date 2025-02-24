#include <stdio.h>
#include <string.h>

void display_message(char * message)
{
  printf(message);
}

char isCharInteger(char c);

int main(int argc, char *argv[]) {
  /* to be completed */
  // next line just shows how to use display_message; could be removed

  // first, check that the number of parameters is correct
  if( argc != 3){
    display_message("Wrong usage, 2 parameters expected: ./sum param1 param2\n");
  }
  
  // now, check that parameters represent integer values
  // declare, implement, and use function isCharInteger
  for(int i = 1; i < argc; i++){
    char * arg = argv[i];
    for(int j = 0; j < strlen(arg); j++){
      if(isCharInteger(arg[j]) == 0){
        display_message("Wrong usage, parameters param1 and param2 should be integers when executing ./sum param1 param2");
        return -1;
      }
    }
  }
  return 0;
}

char isCharInteger(char c)
{
  switch(c){
    case '0':
      return 1;
    case '1':
      return 1;
    case '2':
      return 1;
    case '3':
      return 1;
    case '4':
      return 1;
    case '5':
      return 1;
    case '6':
      return 1;
    case '7':
      return 1;
    case '8':
      return 1;
    case '9':
      return 1;
  }
  return 0;
}
