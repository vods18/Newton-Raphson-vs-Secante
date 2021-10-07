#include "utils.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <matheval.h>


void clean_fgets(char *pos) { //OK
  strtok(pos, "\n");
}

double calculaPolinomioEDerivada( char *p, int n, double x, int bol ){ //OK
  double *px, *dpx;
  double b=p[n], c=b;
  for (int i=n-1; i; --i) {
    b = p[i] + b * x;
    c = b + c * x;
  }

  b = p[0] + b * x;
  *px = b;
  *dpx = c;
  
  return (bol=0) ? b/c : b;
}


//calcula método newton-raphson
double newton_raphson(char *equacao, double x, int grau){

   return (x - calculaPolinomioEDerivada(equacao,grau,x,0)); //retorna aproximação da iteração atual
}

double secante(char *equacao, double x1, double x0, int grau){
  
  double xt = calculaPolinomioEDerivada(equacao,grau,x1,1);
  
  return x1 - ((xt*x1-x0)/(xt-x0));

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

void func_compare(char *equacao, double x0, double epsilon, int max_it){

  double newton_x = x0;
  double secante_x = x0;
  double ni1, si0, si1=x0;
  double newton_crit = 1;
  double secante_crit = 1;
  int i = 0;
  int grau = 2; //fazer funcao para calcular grau do polinomio

  do{

    si0 = si1; //secante anterior anterior
    si1 = secante_x; //secante anterior  
    ni1 = newton_x; //newton anterior  
    
    newton_x = newton_raphson(equacao, newton_x, grau);
    secante_x = secante(equacao, secante_x, si0, grau);
    newton_crit = newton_x - ni1; // criterio 1 para newton
    secante_crit = secante_x - si1; // criterio 1 para secante

    printf("%d         ", i); // OK
    printf("%1.16e         ", newton_x);
    printf("%1.16e         ", newton_crit);
    printf("%1.16e         ", secante_x);
    printf("%1.16e         ", secante_crit);
    printf("%1.16e         ", EA(newton_x, secante_x)); //cálculo OK
    printf("%1.16e         ", ER(newton_x, secante_x)); //cálculo OK
    printf("%" PRId64 "         \n", ULP(newton_x, secante_x)); //cálculo OK


    i++;

  }while(i<max_it && 0<epsilon);
  // implementar método de parada para analizar o erro e substituir 0<epsilon
}
