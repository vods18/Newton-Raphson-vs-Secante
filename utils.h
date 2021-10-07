#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <inttypes.h>

void clean_fgets(char *pos);

double newton_raphson(char *equacao, double newton_x);

double secante(char *equacao, double x1, double x0);

void imprime(int i, double newton_x, double newton_crit, double secante_x, double secante_crit);

double EA(double n, double s);

double ER(double n, double s);

int64_t ULP(double n, double s);

void func_compare(char *equacao, double x0, double epsilon, int max_it);

#endif // __UTILS_H__
