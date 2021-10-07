#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utils.h"
#include <inttypes.h>
#include <matheval.h>


int main (){

  char *equacao = malloc(sizeof(500));
  double x0;
  double epsilon;
  int max_iter;

  fgets(equacao, 24, stdin);
  scanf("%le", &x0);
  scanf("%le", &epsilon);
  scanf("%i", &max_iter);

  clean_fgets(equacao);

  func_compare(equacao, x0, epsilon, max_iter);

}
