#include <stdio.h>

void init(int * tab);
void swap(float * f1, float * f2);
int * alloc (int val);

int main(int argc, char *argv[]) {
  float f1=0.7;
  float f2=1.2;
  swap(&f1, &f2);
  printf("%f\n", f1);
  printf("%f\n", f2);
  // use swap to put value of f1 in f2 and vice-versa
  // use printf to display values of f1 and f2
  
  int * ptr = alloc(7);
  // use printf to look at the content accessible from ptr
  for(int i = 0; i < 300; i++){
    printf("%d\n",ptr[i]);
  }
  return 0;
}

int * alloc (int val){
   int tab[300];
   // initialize elements of tab with value val
   for(int i = 0; i < 300; i++){
    tab[i] = val;
   }
   int * t = tab;
   return t;
}

void swap(float * f1, float * f2)
{
  float  swapper = *f1;
  *f1 = *f2;
  *f2 = swapper;
}
