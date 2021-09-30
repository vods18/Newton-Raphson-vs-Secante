#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int main (){

  char *equacao = malloc(sizeof(500)) ;
  char *x0 = malloc(sizeof(500)) ;
  char *epsilon = malloc(sizeof(500)) ;
  char *max_iter = malloc(sizeof(500)) ;

  fgets(equacao, 24, stdin);
  fgets(x0, 24, stdin);
  fgets(epsilon, 24, stdin);
  fgets(max_iter, 24, stdin);

  clean_fgets(equacao);
  clean_fgets(x0);
  clean_fgets(epsilon);
  clean_fgets(max_iter);

  puts(equacao);
  puts(x0);
  puts(epsilon);
  puts(max_iter);

}
