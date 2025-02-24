#include <stdio.h>

int *alloc_segfault (int val);
int *alloc_silent (int val);
void swap_wrong(float f1, float f2);
void swap_correct(float *f1, float *f2);

int main(int argc, char *argv[]) {
  float f1=0.7;
  float f2=1.2;

  // use swap to put value of f1 in f2 and vice-versa
  // use printf to display values of f1 and f2
  swap_wrong(f1, f2);
  printf("%f, %f -- did not swap values\n", f1, f2);
  swap_correct(&f1, &f2);
  printf("%f, %f -- did swap values\n", f1, f2);


  // use printf to look at the content accessible from ptr
  volatile int * ptr = alloc_silent(7);
  // Explanation:
  // The following code tries to access specific elements of the array tab/ptr.
  // The first access displays the expected value 7, while the second does not
  // and instead displays some random value. The reason is that the table tab is
  // stored on the stack for the function alloc_silent. The allocated memory for
  // the table is, however, freed at the end of the function. The memory area
  // where tab is/was stored is reused as the stack frame for the printf
  // function, which may overwrite some elements of tab with other data (such as
  // the values of local variables of the printf function, or the return
  // address).
  //
  // Why are some elements of the array not overwritten? Because printf reserves
  // space for variables that are not necessarily used. Consequently the
  // corresponding memory addresses are never modified and the value in the
  // array is not overwritten.
  printf("ptr[0] = %d -- should always print 7\n", ptr[0]);
  printf("ptr[250] = %d -- might print 7 or garbage\n", ptr[250]);

  ptr = alloc_segfault(7);
  printf("The program will now crash due to a segmentation fault\n");
  printf("ptr[0] = %d\n", ptr[0]); // program is terminated here
  printf("ptr[250] = %d\n", ptr[250]);

  return 0;
}

int * alloc_segfault (int val){
  int tab[300];
  // initialize elements of tab with value val
  for (int i=0; i < 300; i++)
    tab[i] = val;

  // The compiler issues a warning for the following line:
  // The pointer that is returned points to an address on the stack that is
  // freed by the return. The address thus is not valid and the behavior of the
  // program is *undefined*. Since the behavior is undefined, the compiler chose
  // to replace the actual address of tab by NULL. Dereferencing the pointer
  // then causes a segmentation fault, which will be discussed in detail in
  // INF106.
  return tab;
}

int * alloc_silent (int val){
  int tab[300];
  // initialize elements of tab with value val
  for (int i=0; i < 300; i++)
    tab[i] = val;

  // Contrary to the first version of alloc_segfault, the compiler does not
  // issue a warning -- due to the copy it is unable to detect that an invalid
  // address will be produced (unless you compile with optimizations enabled,
  // e.g. by passing the option -O to gcc). The function thus returns the actual
  // invalid address of tab. Dereferencing the resulting pointer does not cause
  // a segmentation fault, but still accesses an invalid address. Notably, the
  // printf in main might reuse this address to store its local variables at the
  // address of tab. The second printf thus might print garbage.
  int *tmp = tab;
  return tmp;
}

void swap_wrong(float f1, float f2)
{
  float tmp = f1;
  f1 = f2;
  f2 = tmp;
}

void swap_correct(float *f1, float *f2)
{
  float tmp = *f1;
  *f1 = *f2;
  *f2 = tmp;
}
