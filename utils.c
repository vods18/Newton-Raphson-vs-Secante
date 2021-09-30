#include "utils.h"
#include <string.h>


void clean_fgets(char *pos) {
  strtok(pos, "\n");
}

void calculaPolinomioEDerivada( double *p, int n, double x, double *px, double *dpx ){
  double b=p[n], c=b;
  for (int i=n-1; i; --i) {
    b = p[i] + b * x;
    c = b + c * x;
  }

  b = p[0] + b * x;
  *px = b;
  *dpx = c;
}


 \\ calcula método newton-raphson
double newton_raphson(char *equacao, newton_crit, double x){ 
  
  double *px, *dpx;
  calculaPolinomioEDerivada(equacao,n,x,px,dpx);
  newton_raphson = (x - (*px / *dpx));

   return; \\retorna aproximação da iteração atual
}

double secante_x(){


}

double EA(double n, double s){

}

double ER(double n, double s){


}

float ULP(){

}

void (char *equacao, double x){

  double newton_x;
  double secante_x;

  for(int i=0; i<max_it; ++i){

    newton_x = newton_raphson(equacao, newton_crit, x);
    secante_x = secante(equacao, sec_crit, x);

    fprintf("%d  ", i);
    fprintf("%1.16e  ", newton_x);
    fprintf("%1.16e  ", newton_crit);
    fprintf("%1.16e  ", secante_x);
    fprintf("%1.16e  ", secante_crit);
    fprintf("%1.16e  ", EA(newton_x, secante_x));
    fprintf("%1.16e  ", ER(newton_x, secante_x));
    fprintf("%d ", ULP);

  }


}

