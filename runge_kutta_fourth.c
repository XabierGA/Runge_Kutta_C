#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "runge_kutta.h"

/*double k_function(func_t func,double x , double y, double h){
	double k =h*func(x , y);
	return k;
}
	
double k_2(func_t func, double k1 , double x , double y, double h){
	double k2 = h*func(x + h/2 , y + k1/2);
	return k2;
}
*/

double k_3_fourth(func_t func , double k2 , double x , double y ,double h){
	double k3 = h*func(x+ h/2 , y + k2/2);
	return k3;
}

double k_4(func_t func , double k3 , double x , double y , double h){
	double k4 = h*func(x + h , y + k3);
	return k4;
}

double fourth_order(func_t func , k_func kfunc , k2_func k_2  , k2_func k_3_fourth , k2_func k_4 , int n , double a , double b , double initial_condition){
	double h = (b-a)/n;
	double y = initial_condition; 

	double* x = (double*)malloc(n*sizeof(double*));

	for (int i = 0 ; i <n ; i++){
		x[i] = i*h;
		double k1 = kfunc( func , x[i] , y ,h);
		double k2 = k_2(func , k1 , x[i] , y ,h); 
		double k3 = k_3_fourth(func , k2 , x[i] , y ,h);
		double k4 = k_4(func , k3 , x[i] , y ,h);
		y += (k1 +2*k2+ 2*k3 +k4)/6;
		printf("Y at this moment : --> %lf \n" , y);
	}
	return y;
}