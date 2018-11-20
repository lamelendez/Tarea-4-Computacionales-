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

//funciones

float aceleracionx(float x,float y);
float aceleraciony(float y,float x);
void funVelDist(float xvo,float yvo,const char* nombre);
float rk4(float y0,float k1_c,float k2_c,float k3_c,float k4_c);


//para cada angulo con su respectivo sen y cos ya hecho

int main()
{
 
	funVelDist(212,212,"45v.txt");
	funVelDist(295.4,52.1,"10v.txt");
	funVelDist(281.9,102.6,"20v.txt");
	funVelDist(259.8,150,"30v.txt");
	funVelDist(229.8,192.8,"40v.txt");
	funVelDist(192.8,229,"50v.txt");
	funVelDist(150.0,270,"60v.txt");
	funVelDist(102,281.9,"70v.txt");
    return 0;
}


//segun la formulas dadas ax y ay

float aceleracionx(float x,float y)
{
	return(-c*(sqrt(pow(x,2)+pow(y,2))/(m))*x);
}
float aceleraciony(float y,float x)
{
	float t1=-1*g;
	float t2=c*y;
	float t3=((sqrt(pow(x,2)+pow(y,2)))/m);

	return(t1-(t2*t3));
}

//runge Kutta en 4d
float rk4(float y0,float k1_c,float k2_c,float k3_c,float k4_c)
{
 

 return(y0+((h/6.0)*(k1_c + 2*k2_c + 2*k3_c + k4_c)));
}
void funVelDist(float xvo,float yvo,const char* nombre) 
{
	FILE *output; 
	output = fopen(nombre,"w");
	float xinicial = 0;
	float yinicial = 0;
	float contador=0;
	float velactu=0;
	float xve = 0;                   //inicializamos las vs y xs para actualizar, creamos las ks para cada coordenada dependiendo si es para la velocidad y para la posicion, y luego actualizamos segun el metodo runge kutta


	float y_0 = 0;
	float velactuy=0;
        float posicionx= 0;
        float posiciony =0;
	do 	
	{
		float k1_x = h*aceleracionx(xinicial, yinicial); 
		float k2_x = h*aceleracionx(xinicial + 0.5*h, yinicial + 0.5*k1_x); 
		float k3_x = h*aceleracionx(xinicial + 0.5*h, yinicial + 0.5*k2_x); 
		float k4_x = h*aceleracionx(xinicial + h, yinicial + k3_x);
		float k1_y = h*aceleraciony(xve, y_0); 
		float k2_y = h*aceleraciony(xve + 0.5*h, y_0 + 0.5*k1_y); 
		float k3_y = h*aceleraciony(xve + 0.5*h, y_0 + 0.5*k2_y); 
		float k4_y = h*aceleraciony(xve + h, y_0 + k3_y);  


  float k1xi = xvo;
  float k1yi = yvo;

  float k2xi = xvo + k1xi*h*0.5;
  float k2yi = yvo + k1yi*h*0.5;

  float k3xi = xvo + k2xi*h*0.5;
  float k3yi = yvo + k2yi*h*0.5;

  float k4xi = xvo + k3xi*h;
  float k4yi = yvo + k3yi*h;

	
	if (contador==0)
	{
		velactu = xvo;
	 	velactuy = yvo;
		posicionx = xve;
	 	posiciony = xinicial;	
	}
	else
	{
	 	velactu = rk4(xvo,k1_x,k2_x,k3_x,k4_x);
	 	velactuy = rk4(yvo,k1_y,k2_y,k3_y,k4_y);
                posicionx = rk4(xve,k1xi,k2xi,k3xi,k4xi);
	 	posiciony = rk4(xve,k1yi,k2yi,k3yi,k4yi);	
	}
	
		

        
   
        fprintf(output, "%f %f %f %f\n",velactu,velactuy,posicionx,posiciony);
                
   		xvo = velactu;
		yvo = velactuy;
                xve = posicionx;
		y_0 = posiciony;
		contador++;      
	}

	while(yvo>=0);
fclose(output);
}
