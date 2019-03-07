#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "runge_kutta.h"

double second_order(func_t func, k_func k_fun , int n , double a ,double b , double initial_condition){
	double h = (b-a)/n;
	double y = initial_condition;

	double* x = (double*)malloc(n*sizeof(double*));
	for (int i = 0; i<n ; i++){
		x[i] = i*h;
		double k = k_fun(func, x[i] , y ,h);
		y += h*func(x[i]+h/2 , y + k/2);
		//printf("y is at this moment ---> %lf\n" , y );
	}
	return y;
}

double k_function(func_t func,double x , double y, double h){
	double k =h*func(x , y);
	return k;
}




double second_order_several_equations(func_vector* func , k_funct_vector* k_fun , int n , double a , double b , double* initial_condition , int width){
	double h = (b-a)/n; 
	double y[width];
	for (i = 0; i < len ; i++){
		y[i][0] = initial_condition[i];
	}

	double*x = (double*)malloc(n*sizeof(double*));

	for (int i = 0; i < n ; i++){
		x[i] = i*h;
		for (j = 0; j < len ; j++){
			double k[i] = k_fun(func , x[i] , y[i] , h);
			y[i]+= h*func(x[i] + h/2, y[i] +k/2); 
			printf("Printing y ----> %lf" , y[i]);
		}
	}
	return y;

}

double k_function_vector(func_vector* func , double x , double* y , double h, int size){
	double* k[size]; 
		for (int i = 0; i< size ; i++){
			k[i] = func[i](x , y);
		}
}