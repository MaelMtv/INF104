// This file is almost empty... We think you should be able to start from
// scratch. Of course, you can reuse code you wrote in previous labs.


int main(int argc, char *argv[]) {
  /* To be completed */
  int i;
  int j;

  // display a message to indicate what users should write
  // use printf to do that
  printf("Enter a number\n");
  // wait until users have provided you information
  // use scanf to do that
  char fint = scanf("%d", &i);
  // check that information provided is an integer
  if(fint != 1){
    printf("Error, input is not an integer.\n");
    return -1;
  }
  // repeat previous steps to get a second integer
  printf("Enter a second number\n");
  char sint = scanf("%d", &j);
  if(sint != 1){
    printf("Error, input is not an integer.\n");
    return -2;
  }
  // compute the sum of integer values and display it
  printf("The sum is %d\n", i+j);
  return 0;
}
