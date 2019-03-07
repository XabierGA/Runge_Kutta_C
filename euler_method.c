#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float function(float,float);
float derivative_x(float , float); 
float derivative_y(float , float);
float g_function(float);
double euler_method(float (*func)(float, float), int , float , float);
double taylor_series (float (*func)(float , float) , int  , float  , float , float (*der_x)(float , float) , float (*der_y)(float , float));
double implicit_method(float (*func)(float , float) , float(*g)(float) , int , float  , float );


int main() {

	printf("Solution to the following differential equation: \n"); 
	double sol_euler;
	double sol_taylor;
	double sol_implicit;
	float a = 0;
	float b = 1; 
	unsigned long int n = 10000;
	float (*pointer)(float , float) = &function;
	float (*pointer_x)(float , float) = &derivative_x;
	float (*pointer_y)(float , float) = &derivative_y;
	float (*pointer_g)(float) = &g_function;
	sol_euler = euler_method(pointer , n , a , b);
	sol_taylor = taylor_series(pointer , n , a ,b ,pointer_x , pointer_y); 
	sol_implicit = implicit_method(pointer,  pointer_g , n , a ,b);
	printf("Solution is %lf\n" , sol_euler);
	printf("Solution Taylor is %lf \n" , sol_taylor);
	printf("Solution Implicit is %lf \n" , sol_implicit);

}

float function(float x , float y){
	float mult; 
	mult = -x*y;
	return mult;
}

float derivative_x( float x , float y){
	return -y;
}

float derivative_y( float x , float y){
	return -x;
}

float g_function(float x){
	return -x;
}



double euler_method(float (*func)(float , float) , int n , float a , float b){
	float y = 1;
	float h = (b-a)/n;
	float *x; 
	x = (float*)malloc(n*sizeof(float*));
	for (int i = 0; i<n ; i++){
		x[i] = i*h;
		//printf("Result function :  --->%f \n" , func(x[i],y));
		y+= h*(func(x[i] , y));
	}
	free(x);
	return y;

}

double taylor_series (float (*func)(float , float) , int n , float a , float b , float (*der_x)(float , float) , float (*der_y)(float , float)){
	float y = 1; 
	float h= (b-a)/n; 
	float *x;
	x = (float*)malloc(n*sizeof(float*));
	for (int i = 0 ; i < n ; i++){
		x[i] = i*h;
		y+= h*func(x[i] , y) + h*h*(der_x(x[i], y) + func(x[i] , y) * der_y(x[i] , y))/2.0;
	}
	free(x);
	return y;
}

double implicit_method(float (*func)(float , float) , float(*g)(float) , int n , float a , float b){
	float y = 1;
	float h = (b-a)/n;
	float *x;
	x = (float*)malloc(n*sizeof(float*));
	for (int i = 1; i<n ; i++){
		x[i] = i*h;
		y = y * (1 + g(x[i-1])*h/2)/(1-g(x[i])*h/2);
	}
	free(x);
	return y;
}