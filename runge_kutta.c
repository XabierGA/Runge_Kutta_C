#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M_PI 3.14159265358979323846
typedef double(*func_t)(double,double);
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

double func_y(double p,double y){
	return p;
}

double func_p(double p ,double y){
	return -4*M_PI*M_PI*p;
}


int main() { 
	int n = 20;
	/*k_func pointer_k = &k_function;
	func_t pointer = &function;
	k2_func pointer_k2 = &k_2;
	k3_third_funct pointer_k3 = &k_3_third;
	k2_func pointer_k3_fourth = &k_3_fourth;
	k2_func pointer_k4 = &k_4;
	double sol_second = second_order(pointer , pointer_k , n, 0 ,1 , 1);
	printf("Solution second order is : ---> %lf \n" , sol_second);
	double sol_third = third_order(pointer , pointer_k , pointer_k2 , pointer_k3 , n, 0 ,1 ,1);
	printf("Solution third order is : ---> %lf \n" , sol_third);
	double sol_fourth = fourth_order(pointer , pointer_k , pointer_k2 , pointer_k3_fourth , pointer_k4, n , 0 ,1 ,1);
	printf("Solution to fourth order : ---> %lf" , sol_fourth);*/
	func_t pointer_displacement= &func_y;
	func_t pointer_momentum = &func_p;
	k_func pointer_k = &k_function;
	k2_func pointer_k2 = &k_2;
	k2_func pointer_k3_fourth = &k_3_fourth;
	k2_func pointer_k4 = &k_4;


	func_t arr[2] = {pointer_displacement , pointer_momentum};
	double initial_conditions[2] = {0 ,1};
	double solutions[2];
	for (int i =0 ; i<2 ; i++){
		solutions[i] = fourth_order(arr[i] , pointer_k , pointer_k2 , pointer_k3_fourth , pointer_k4 , n ,0 ,1 ,initial_conditions[i]);
		printf("Solutions ---> : %lf\n" , solutions[i]);
	}

	return 0;
}


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

double function(double x , double y){
	double result = -x*y;
	return result;
}


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

double k_2(func_t func, double k1 , double x , double y, double h){
	double k2 = h*func(x + h/2 , y + k1/2);
	return k2;
}

double k_3_third(func_t func , double k1 , double k2 , double x , double y , double h){
	double k3 = h*func(x+ h , y -k1 +2*k2);
	return k3;
}


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