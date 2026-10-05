#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dvector.h"

dvector F(double x, dvector Y);
dvector euler_vect(double x, dvector Y, double h);

int main() {
	FILE*fich;
	
	double h=0.01;
	double x0=0.0;
	double x;
	double x_max=10.0;
	
	dvector Y(2);
	
	//Conditions initiales
	Y[0]=1;
	Y[1]=0;
	
	fich=fopen("resultats_oscillateur.txt", "w");
	
	x=x0;
	
	do{
		fprintf(fich, "%lf %lf\n", x, Y[0]);
		
		Y = euler_vect(x, Y, h);
		
		x = x + h;
		
	}while(x<x_max);
	
	fclose(fich);
}

dvector F(double x, dvector Y){
	double w0=2.0;
	dvector V(2);
	
	V[0] = Y[1];
	V[1] = -(w0*w0)*Y[0];
	
	return V;
}

dvector euler_vect(double x, dvector Y, double h){
	dvector K1(2);
	
	K1 = h*F(x, Y);
	
	return Y+K1;
}
