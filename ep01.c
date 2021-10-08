#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utils.h"
#include <inttypes.h>
#include <matheval.h>


int main (){

  //declaracao de variáveis e vetor de acordo com formato proposto
  char *equacao = malloc(sizeof(500));
  double x0;
  double epsilon;
  int max_iter;

  //leitura das variáveis a partir de um arquivo 
  fgets(equacao, 24, stdin);
  scanf("%le", &x0);
  scanf("%le", &epsilon);
  scanf("%i", &max_iter);

  clean_fgets(equacao);//"limpeza" da string

  func_compare(equacao, x0, epsilon, max_iter); //execução do laço principal para a execução das aproximações de cada iteração necessária

}
