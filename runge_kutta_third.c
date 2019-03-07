#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "runge_kutta.h"

double third_order(func_t func , k_func kfunc , k2_func k_2 , k3_third_funct k_3_third , int n , double a , double b , double initial_condition){
	double h = (b-a)/n;
	double y = initial_condition; 

	double* x = (double*)malloc(n*sizeof(double*));

	for (int i = 0; i<n ; i++){
		x[i] = i*h;
		double k1 = kfunc(func , x[i] , y, h);
		double k2 = k_2(func , k1 , x[i], y, h);
		double k3 = k_3_third(func , k1 , k2 , x[i] , y ,h);
		y += (k1 + 4*k2 +k3)/6.0;
	}

	return y;
}

/*double k_function(func_t func,double x , double y, double h){
	double k =h*func(x , y);
	return k;
}*/

/*double k_2(func_t func, double k1 , double x , double y, double h){
	double k2 = h*func(x + h/2 , y + k1/2);
	return k2;
}*/

double k_3_third(func_t func , double k1 , double k2 , double x , double y , double h){
	double k3 = h*func(x+ h , y -k1 +2*k2);
	return k3;
}