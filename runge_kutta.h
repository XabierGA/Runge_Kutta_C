#ifndef RUNGE_KUTTA_H
#define RUNGE_KUTTA_H

typedef double(*func_t)(double,double);
typedef double(*func_vector)(double , *double);
typedef double(*k_func)(func_t,double, double , double);
typedef double(*k2_func)(func_t , double , double ,double ,double);
typedef double(*k3_third_funct)(func_t , double, double ,double ,double ,double);
double second_order(func_t, k_func  , int , double , double , double);
double k_function(func_t , double , double ,double);
double function (double , double);
double k_2 (func_t , double ,double ,double ,double);
double k_3_third (func_t , double ,double ,double ,double, double);
double third_order(func_t , k_func , k2_func , k3_third_funct , int , double ,double , double);
double k_3_fourth(func_t , double,double ,double, double);
double k_4(func_t , double  ,double ,double, double);
double fourth_order(func_t, k_func , k2_func , k2_func, k2_func, int , double, double , double);
double second_order_several_equations(func_t* , k_func* , int , double  , double  , double*  , int);

#define M_PI 3.14159265358979323846
#endif