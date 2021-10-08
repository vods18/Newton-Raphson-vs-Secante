#include "utils.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <matheval.h>
#include <assert.h>


void clean_fgets(char *pos) { //função para "limpar" string
  strtok(pos, "\n");
}


double newton_raphson(char *equacao, double x){ //cálculo de aproximação utilizando método newton-raphson

  void *f, *f_dv;
  double func, func_dv;
  f = evaluator_create(equacao); //utilizamos as funções de cálculo de funções definidas pela biblioteca MATHEVAL
  assert(f);
  func = evaluator_evaluate_x(f, x);
  f_dv = evaluator_derivative_x(f); //também utilizamos essa biblioteca para calcular a derivada
  func_dv = evaluator_evaluate_x(f_dv, x);

   return (x - (func/func_dv)); //retorna aproximação da iteração atual
}

double secante(char *equacao, double x1, double x0){ //cálculo da aproximação para o método da secante

  void *f;
  double func1, func2;
  f = evaluator_create(equacao); //utilizamos a funções de cálculo de funções definidas pela biblioteca MATHEVAL
  assert(f);
  func1 = evaluator_evaluate_x(f, x1);
  func2 = evaluator_evaluate_x(f, x0);

  //separamos o cálculo em parte de cima e de baixo da fração para facilitar o entendimento 
  double cima = (func1 * (x1-x0));
  double baixo = (func1 - func2);

  return (x1 - (cima/baixo));
}

double EA(double n, double s){ //cálculo do Erro Absoluto
  
  return fabs(s - n);
}

double ER(double n, double s){ //cálculo do Erro Relativo
  
  double temp = 0;
  temp = (s-n)/n;
  return fabs(temp);
}

long int ULP(double n, double s){ //cálculo da ULP

  if(n == s){
    return 0;
  }

  long int in, is;
  memcpy(&in, &n, sizeof(double));
  memcpy(&is, &s, sizeof(double));

  return abs(is- in- 1);
}

void imprime(int i, double newton_x, double newton_crit, double secante_x, double secante_crit){

  //impressão dos valores para um arquivo de formato .csv, cada valor será uma coluna
  printf("%d         ", i); 
  printf("%1.16e         ", newton_x); 
  printf("%1.16e         ", newton_crit);
  printf("%1.16e         ", secante_x);
  printf("%1.16e         ", secante_crit);
  printf("%1.16e         ", EA(newton_x, secante_x)); 
  printf("%1.16e         ", ER(newton_x, secante_x)); 
  printf("%" PRId64 "         \n", ULP(newton_x, secante_x)); 

}

void func_compare(char *equacao, double x0, double epsilon, int max_it){

  //declaração das variáveis necessárias para a execução das iterações de newton e secante
  double newton_x = x0, secante_x = x0;
  double ni1, santigaantiga=0, santiga=x0;
  double newton_crit = 1, secante_crit = 1;
  int i = 0;

  do{

    if (i==0){ //imprime valores iniciais
      imprime(i,newton_x,newton_crit,secante_x,secante_crit);
      santigaantiga = secante_x; //secante anterior anterior
      i++;
      continue;
    }

    if (i==1){ //realiza primeira aproximação apenas com newton, pois secante precisa de 2 valores anteriores
      ni1 = newton_x; //newton anterior
      newton_x = secante_x = newton_raphson(equacao, newton_x);
      newton_crit = fabs(newton_x - ni1); //criterio de parada para newton
      secante_crit = newton_crit; //laço 1 critério de secante será o mesmo de newton
      imprime(i,newton_x,newton_crit,secante_x,secante_crit);
      santiga = secante_x;
      i++;
      continue;
    }
    if (i!=2){ //a partir do laço 2 podemos realizar as aproximações para secante junto ao do newton
      santigaantiga = santiga; //secante anterior anterior
      santiga = secante_x; //secante anterior
    }

    ni1 = newton_x; //newton anterior

    if (newton_crit>epsilon)
      newton_x = newton_raphson(equacao, newton_x);

    if (secante_crit>epsilon)
      secante_x = secante(equacao, santiga, santigaantiga);

    newton_crit = fabs(newton_x - ni1); // criterio para parada de newton
    secante_crit = fabs(secante_x - santiga); // criterio para parada da secante

    imprime(i,newton_x,newton_crit,secante_x,secante_crit); //impressão de valores a partir do laço 2
    
    i++;

  }while((i<max_it) && (newton_crit>epsilon && secante_crit>epsilon)); //executamos iterações enquanto valores cumprem com os critérios apresentados
  
}
