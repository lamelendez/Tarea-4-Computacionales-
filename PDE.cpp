#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//inicializamos las constantes 

 int filas = 500,columnas = 500,r=50,h=1,N=100,centrox=250,centroy=250;  
 float k=1.62,cp=820,p=2.71,dt=0.00001;
 float v=k/(cp*p);

void circuloV(float seccion[][columnas],int r, int centrox,int centroy);
void condicionesFrontera(float seccion[][columnas],int caso);
void ecuaciondifin1(float seccion[][columnas]);

int main()
{
 return 0;
}

//funcion que fija la temperatura constante del centro en forma de circulo con el diametro de la varilla

void circuloV(float seccion[][columnas],int r, int centrox,int centroy)
{
	for(int i = centrox - r; i <= centrox + r; i++)
	{
   for(int j = centroy - r; j <= centroy + r; j++)
   	{
       if((centrox-r)*(centrox-r) + (centroy-r)*(centroy-r) <= r*r)
       {
         seccion[i][j]=100;
       }
   	}
	}
}

//condiciones de frontera dadas por el enunciado segun los 3 casos.
void condicionesFrontera(float seccion [][columnas], int caso)
{
	if (caso==1)   //condicion de frontera fija 10 grados
		{
		for (int y = 0 ; y < columnas-1 ; y++)
			{	seccion[0][y]=10;
				seccion[filas-1][y]=10;
				seccion[y][0]=10;
				seccion[y][columnas-1]=10;
			}

		}	
	if (caso==2)
		{
	
		for (int y = 0 ; y < columnas-1 ; y++)
			{	seccion[0][y]=10;
				seccion[filas-1][y]=10;
				seccion[y][0]=10;
				seccion[y][columnas-1]=10;

			}


		}	
	if (caso==3)
		{

		for (int y = 0 ; y < columnas-1 ; y++)
			{
				seccion[0][y]=10;
				seccion[filas-1][y]=10;
				seccion[y][0]=10;
				seccion[y][columnas-1]=10;

			}

		}

}

//ecuacion de propagacion 

void ecuaciondifin1(float seccion[][columnas])
{
	int contador = 0;
    
    do 	
	for (int x = 1 ; x < filas-1 ; x++)
	{
	    for (int y = 1 ; y < columnas-1 ; y++)
			{
                        circuloV(seccion,r,centrox,centroy);
			seccion[x][y]=(1-(4*dt*v)/(h*h))*seccion[x][y]+(dt*v/h*h)*(seccion[x+1][y]+seccion[x][y+1]+seccion[x-1][y]+seccion[x][y-1]);
			}
	}
	while (++contador <=N);
}
