// This file is almost empty... We think you should be able to start from
// scratch. Of course, you can reuse code you wrote in previous labs.
#include <stdio.h>

int main(int argc, char *argv[]) {
  /* To be completed */
   if(argc!=3)
  {
    printf("Wrong usage: expected ./sum_fscanf file_name");
    return -1;
  }

  FILE * f, *fp;
  char * numbers;
  int words_nb,i,j,ret,result;

  printf ("number of words to read?\n");
  scanf( "%d", &words_nb);

  // check that the user gave a correct number of parameters
  // Usage: ./sum_fscanf file_name

  // open file_name and retreive integer values it contains
  // use fopen and fscanf to do that
  f = fopen(argv[1], "r");
  // check for the occurence of errors when using fopen and fscanf,
  // display an error message and quit in case of errors.
  if(f == NULL){
    printf("Error: file %s does not exist\n", argv[1]);
    return -2;
  }
  for(i = 0; i <words_nb; i++){
    ret = fscanf(f, "%d", &(numbers[i]));
    if (ret != 1){
     printf ("i = %d : error when reading input stream\n", i);
     return -3;
    }
  }

  for(j = 0; j <words_nb; j++){
    result = result + numbers[j];
  }  

  // first variant: compute the sum of integer values and display it
  printf("Result = %d\n", result);
  // second variant: compute the sum of integer values and print it in 
  // an output file
  fp = fopen (argv[2], "w+");
  if(fp == NULL){
    printf("Error: file %s does not exist\n", argv[2]);
    return -4;
  }
  fprintf(fp, "%d", result);

  return 0;
}
