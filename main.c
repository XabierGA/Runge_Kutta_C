#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "runge_kutta.h"


double func_y(double t,double y , double p){
	return p;
}

double func_p(double t ,double y , double p){
	return -4*M_PI*M_PI*y;
}

int main() { 
	int n = 20;
	int n_equations = 2;

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
	func_three pointer_displacement= &func_y;
	func_three pointer_momentum = &func_p;
	k_func pointer_k = &k_function;
	/*k2_func pointer_k2 = &k_2;
	k2_func pointer_k3_fourth = &k_3_fourth;
	k2_func pointer_k4 = &k_4;*/


	/*func_t arr[2] = {pointer_displacement , pointer_momentum};
	double initial_conditions[2] = {0 ,1};
	double solutions[2];
	for (int i =0 ; i<2 ; i++){
		solutions[i] = fourth_order(arr[i] , pointer_k , pointer_k2 , pointer_k3_fourth , pointer_k4 , n ,0 ,1 ,initial_conditions[i]);
		printf("Solutions ---> : %lf\n" , solutions[i]);
	}*/
	double *solutions[n]; 
	*func_t arr[n] = {pointer_displacement , pointer_momentum};
	*k_func arr_k[2] = {k_function,k_function};
	double*initial_conditions[2] = {0,1};

	solutions = double second_order_several_equations(arr , arr_k, n , 0 , 1 , initial_conditions , n_equations);

	for (int i = 0; i<2 ; i++){
		printf("Solutions --->: %lf" , solutions[i]);
	}

	return 0;
}