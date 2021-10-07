#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <inttypes.h>

void clean_fgets(char *pos);

double calculaPolinomioEDerivada( char *p, int n, double x, int bol );

double newton_raphson(char *equacao, double x, int grau);

double secante_x(char *equacao, double x, int grau);

double EA(double n, double s);

double ER(double n, double s);

int64_t ULP(double n, double s);

void func_compare(char *equacao, double x0, double epsilon, int max_it);

#endif // __UTILS_H__
