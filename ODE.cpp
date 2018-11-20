#include <iostream>
#include <iomanip>
#include <cmath>
#include <functional>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define PI 3.14159265
const float g=10.0,c=0.2,m=0.2,h=0.01,N=10;
const int filas = 30,columnas = 4;
float a_x(float x,float y)
{
	return(-c*(sqrt(pow(x,2)+pow(y,2))/(m))*x);
}
float a_y(float y,float x)
{
	float t1=-1*g;
	float t2=c*y;
	float t3=((sqrt(pow(x,2)+pow(y,2)))/m);

	return(t1-(t2*t3));
}

float rk4(float y0,float k1_c,float k2_c,float k3_c,float k4_c)
{
 

 return(y0+((h/6.0)*(k1_c + 2*k2_c + 2*k3_c + k4_c)));
}
void sol(float xvo,float yvo,const char* nombre)
{
	FILE *output; 
	output = fopen(nombre,"w");
	float x_01 = 0;
	float y_01 = 0;
	float contador=0;
	float tx_1=0;
	float x_0 = 0;
	float y_0 = 0;
	float ty_1=0;
        float txv_1= 0;
        float tyv_1 =0;
	do 	
	{
		float k1_x = h*a_x(x_01, y_01); 
		float k2_x = h*a_x(x_01 + 0.5*h, y_01 + 0.5*k1_x); 
		float k3_x = h*a_x(x_01 + 0.5*h, y_01 + 0.5*k2_x); 
		float k4_x = h*a_x(x_01 + h, y_01 + k3_x);
		float k1_y = h*a_y(x_0, y_0); 
		float k2_y = h*a_y(x_0 + 0.5*h, y_0 + 0.5*k1_y); 
		float k3_y = h*a_y(x_0 + 0.5*h, y_0 + 0.5*k2_y); 
		float k4_y = h*a_y(x_0 + h, y_0 + k3_y);  


  float k1xi = xvo;
  float k1yi = yvo;

  float k2xi = xvo + k1xi*h*0.5;
  float k2yi = yvo + k1yi*h*0.5;

  float k3xi = xvo + k2xi*h*0.5;
  float k3yi = yvo + k2yi*h*0.5;

  float k4xi = xvo + k3xi*h;
  float k4yi = yvo + k3yi*h;

	if (contador==1)
	{
	 	tx_1 = rk4(xvo,k1_x,k2_x,k3_x,k4_x);
	 	ty_1 = rk4(yvo,k1_y,k2_y,k3_y,k4_y);	
	}
	else if (contador==0)
	{
		tx_1 = xvo;
	 	ty_1 = yvo;
		txv_1 = x_0;
	 	tyv_1 = x_01;	
	}
	else
	{
	 	tx_1 = rk4(xvo,k1_x,k2_x,k3_x,k4_x);
	 	ty_1 = rk4(yvo,k1_y,k2_y,k3_y,k4_y);
                txv_1 = rk4(x_0,k1xi,k2xi,k3xi,k4xi);
	 	tyv_1 = rk4(x_0,k1yi,k2yi,k3yi,k4yi);	
	}
	
		

        /* save data in laplace.dat */
   
        fprintf(output, "%f %f %f %f\n",tx_1,ty_1,txv_1,tyv_1);
                
   		xvo = tx_1;
		yvo = ty_1;
                x_0 = txv_1;
		y_0 = tyv_1;
		contador++;      
	}

	while(yvo>=0);
fclose(output);
}


int main()
{
//45 
	sol(212,212,"45v.txt");
//10
	sol(295.4,52.1,"10v.txt");
//20
	sol(281.9,102.6,"20v.txt");
//30
	sol(259.8,150,"30v.txt");
//40
	sol(229.8,192.8,"40v.txt");
//50
	sol(192.8,229,"50v.txt");
//60
	sol(150.0,270,"60v.txt");
//70
	sol(102,281.9,"70v.txt");
    return 0;
}



