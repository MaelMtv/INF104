#include <stdio.h>
#include <string.h>

int my_strcmp(char * str1, char * str2);
void sort_string_array(char ** tab, int nb_of_elements);

int main(int argc, char *argv[])
{
  // We initialize here a set of strings in order to test your implementation
  char * GoT_str1 = "Ned Stark";
  char * GoT_str2 = "Jon Snow";
  char * GoT_str3 = "Jon Arryn";
  char * GoT_str4 = "Eddard Stark";
  char * GoT_str5 = "Catelyn Stark";
  char * GoT_str6 = "Talisa Maegyr";
  char * GoT_str7 = "Tywin Lannister";
  char * GoT_str8 = "Lancel Lannister";
  char * GoT_str9 = "Daenerys Targaryen";
  char * GoT_str10 = "Davos Mervault";
  char * GoT_str11 = "Walder Frey";
  char * GoT_str12 = "Brynden Tully";
  char * GoT_str13 = "Trystan Martell";


  printf("Start tests of strcmp\n");

  // we test strcmp with identical strings here
  int cmp = my_strcmp(GoT_str1, GoT_str1);
  if(cmp!=0)
  {
    printf("Error: first test of strcmp failed\n");
    return -1;
  }

  // we test my_strcmp with str1 < str2
  cmp = my_strcmp(GoT_str2, GoT_str1);
  if(cmp!=-1)
  {
    printf("Error: second test of my_strcmp failed\n");
    return -2;
  }

  // we test my_strcmp with str1 > str2
  cmp = my_strcmp(GoT_str1, GoT_str2);
  if(cmp!=1)
  {
    printf("Error: third test of my_strcmp failed\n");
    return -3;
  }

  printf("Tests of strcmp passed, start implementing sort_string_array\n");
  char * game_of_thrones_names[15] = {GoT_str1,
    GoT_str2,
    GoT_str3,
    GoT_str4,
    GoT_str2,
    GoT_str5,
    GoT_str6,
    GoT_str7,
    GoT_str8,
    GoT_str9,
    GoT_str10,
    GoT_str11,
    GoT_str12,
    GoT_str13,
    GoT_str8};

  sort_string_array(game_of_thrones_names, 15);

  int sorted_array_iter;
  printf("Sorted names:\n");
  for(sorted_array_iter=0;sorted_array_iter<15;sorted_array_iter++)
  {
    printf("\t%s\n", game_of_thrones_names[sorted_array_iter]);
  }
  printf("Verify that names have been sorted correctly\n");
  return 0;
}

int my_strcmp(char * str1, char * str2)
{
  int size1 = strlen(str1);
  int size2 = strlen(str2);
  int size = size1 < size2 ? size1 : size2;
  int i = 0;
  while(i < size){
    char char1 = str1[i];
    char char2 = str2[i];
    if(char1 < char2){
      return -1;
    }
    else{
      if(char2 < char1){
        return 1;
      }
    }
    i++;
  }
  if(size < size1){
    return 1;
  }
  else{
    if(size < size2){
      return -1;
    }
    else{
      return 0;
    }
  }
}

void sort_string_array(char ** tab, int nb_of_elements)
{
  int i,k;
  for(i = 1; i < nb_of_elements; i++){
    for(k = i; k > 0; k--){
      if(my_strcmp(tab[k], tab[k-1]) < 0){
        char * swapper = tab[k];
        tab[k] = tab[k-1];
        tab[k-1] = swapper;
      }
    }
  }
}
