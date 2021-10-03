#include "utils.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


void clean_fgets(char *pos) { //OK
  strtok(pos, "\n");
}

void calculaPolinomioEDerivada( double *p, int n, double x, double *px, double *dpx ){ //OK
  double b=p[n], c=b;
  for (int i=n-1; i; --i) {
    b = p[i] + b * x;
    c = b + c * x;
  }

  b = p[0] + b * x;
  *px = b;
  *dpx = c;
}


//calcula método newton-raphson
double newton_raphson(char *equacao, double newton_crit, double x){

  // double *px, *dpx;
  // calculaPolinomioEDerivada(equacao,n,x,px,dpx);
  // newton_raphson = (x - (*px / *dpx));

   return 1; //retorna aproximação da iteração atual
}

double secante(){
  return 1;

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
  double newton_crit = 0;
  double secante_crit = 0;
  int i = 0;

  do{

    newton_x = newton_raphson(equacao, newton_crit , newton_x);
    secante_x = secante(equacao, secante_crit, secante_x);
    newton_crit = 0; // implementar calculo
    secante_crit = 0; // implementar calculo

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
