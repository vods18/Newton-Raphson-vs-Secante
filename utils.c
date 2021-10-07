#include "utils.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <matheval.h>
#include <assert.h>


void clean_fgets(char *pos) { //OK
  strtok(pos, "\n");
}

//calcula método newton-raphson
double newton_raphson(char *equacao, double x){

  void *f, *f_dv;
  double func, func_dv;
  f = evaluator_create(equacao);
  assert(f);
  func = evaluator_evaluate_x(f, x);
  f_dv = evaluator_derivative_x(f);
  func_dv = evaluator_evaluate_x(f_dv, x);

   return (x - (func/func_dv)); //retorna aproximação da iteração atual
}

double secante(char *equacao, double x1, double x0){

  void *f;
  double func1, func2;
  f = evaluator_create(equacao);
  assert(f);
  func1 = evaluator_evaluate_x(f, x1);
  func2 = evaluator_evaluate_x(f, x0);

  double cima = (func1 * (x1-x0));
  double baixo = (func1 - func2);  

  return (x1 - (cima/baixo));
}

double EA(double n, double s){ //OK
  //Erro absoluto real
  return s - n;
}

double ER(double n, double s){ //OK
  // Erro relativo real
  double temp = 0;
  temp = (s-n)/n;
  return fabs(temp);
}

int64_t ULP(double n, double s){ //OK

  if(n == s){
    return 0;
  }

  int64_t in, is;
  memcpy(&in, &n, sizeof(double));
  memcpy(&is, &s, sizeof(double));

  int64_t distance = is - in;
  if (distance < 0) {
    distance = -distance;
  }
  distance = distance -1;
  return distance;
}

void imprime(int i, double newton_x, double newton_crit, double secante_x, double secante_crit){

  printf("%d         ", i); // OK
  printf("%1.16e         ", newton_x); //OK
  printf("%1.16e         ", newton_crit);
  printf("%1.16e         ", secante_x);
  printf("%1.16e         ", secante_crit);
  printf("%1.16e         ", EA(newton_x, secante_x)); //cálculo OK
  printf("%1.16e         ", ER(newton_x, secante_x)); //cálculo OK
  printf("%" PRId64 "         \n", ULP(newton_x, secante_x)); //cálculo OK

}

void func_compare(char *equacao, double x0, double epsilon, int max_it){

  double newton_x = x0, secante_x = x0;
  double ni1, santigaantiga=0, santiga=x0;
  double newton_crit = 1, secante_crit = 1;
  int i = 0;
  
  do{

    imprime(i,newton_x,newton_crit,secante_x,secante_crit);

    if (i>0)
      santigaantiga = santiga; //secante anterior anterior
    santiga = secante_x; //secante anterior  
    ni1 = newton_x; //newton anterior 

    if (newton_crit>epsilon)
      newton_x = newton_raphson(equacao, newton_x);
    
    if (secante_crit>epsilon)
      secante_x = secante(equacao, santiga, santigaantiga);

    newton_crit = fabs(newton_x - ni1); // criterio 1 para newton
    secante_crit = fabs(secante_x - santiga); // criterio 1 para secante


    i++;

  }while(i<max_it && (newton_crit>epsilon || secante_crit>epsilon));
  // implementar método de parada para analizar o erro e substituir 0<epsilon
}
