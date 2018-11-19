#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

//inicializamos las constantes 

const int filas = 50,columnas = 50,r=5,N=2001,centrox=25,centroy=25;
const  float k=1.62e4,cp=820e10,p=2.71,h=1.0;
const float v=2710,dt=(h*h)/(4*v);
// v= 2710 k/cp*p


//funciones 

void circuloV(float seccion[][columnas],int r, int centrox,int centroy);
void condicionesFrontera(float seccion[][columnas],float temperatura,int caso);
void ecuaciondifin1(float seccion[][columnas]);
void ecuaciondifin2(float seccion[][columnas]);
void ecuaciondifin3(float seccion[][columnas]);
void datos(float seccion[][columnas], string nombre);
double prom(float seccion[][columnas]);

int main()
{
 float rocaf[filas][columnas] = {}; 
 float rocaa[filas][columnas] = {};
 float rocap[filas][columnas] = {};
 ecuaciondifin1(rocaf);
 ecuaciondifin2(rocaa);
 ecuaciondifin3(rocap);
return 0;
}
//guarda los datos en un archivo txt 
void datos(float seccion[][columnas], const char* nombre)
{   FILE *output;      
   output = fopen(nombre,"w");  
   for (int i=0; i<filas-1 ; i++)         
   {  if(i!=0)
      {
      fprintf(output, "\n");  
      }
      for (int j=0; j<columnas-1; j++) 
      {
      fprintf(output, "%f,",seccion[i][j]);
      }          
   } 
   fclose(output);
}



//funcion que fija la temperatura constante del centro en forma de circulo con el diametro de la varilla

void circuloV(float seccion[][columnas],int r, int centrox,int centroy)
{
	for(int i = centrox - r; i <= centrox + r; i++)
	{
   for(int j = centroy - r; j <= centroy + r; j++)
   	{
       if((i-centrox)*(i-centrox) + (j-centroy)*(j-centroy) <= r*r)
       {
         seccion[i][j]=100;
       }
   	}
	}
}

//condiciones de frontera dadas por el enunciado segun los 3 casos.
void condicionesFrontera(float seccion [][columnas],float temperatura, int caso)
{
	if (caso==1)
		{
		for (int i = 0 ; i < columnas ; i++)
			{seccion[48][i]=temperatura;
		         seccion[i][48]=temperatura;
			  seccion[0][i]=temperatura;
			seccion[i][0]=temperatura;
			}
		}	
	if (caso==2)
		{
	
		for (int i = 0 ; i < columnas-1 ; i++)
			{seccion[0][i]=seccion[1][i];
			 seccion[columnas-2][i]=seccion[columnas-3][i];
			 seccion[i][0]=seccion[i][1];
			 seccion[i][columnas-2]=seccion[i][columnas-3];
	        }
		}	
	if (caso==3)
		{

		for (int i = 0 ; i < columnas-1 ; i++)
			{seccion[0][i]=seccion[columnas-2][i];
			 seccion[columnas-2][i]=seccion[0][i];
			 seccion[i][0]=seccion[i][columnas-2];
			 seccion[i][columnas-2]=seccion[i][0];
                }
		}
}

//ecuacion de propagacion 

//para bordes fijos
void ecuaciondifin1(float seccion[][columnas])
{
	int contador = 0;
   do 	
    for (int x = 1 ; x < filas-2 ; x++)
     {	for (int y = 1 ; y < columnas ; y++)
	{
	circuloV(seccion,r,centrox,centroy);
        seccion[x][y]=(1-(4*dt*v)/(h*h))*seccion[x][y]+(dt*v/h*h)*(seccion[x+1][y]+seccion[x][y+1]+seccion[x-1][y]+seccion[x][y-1]);
	condicionesFrontera(seccion,10.0,1);
	}
	if (contador==1)
		{datos(seccion,"fi1o.txt");}		
	else if(contador==500)
		{datos(seccion,"fi2o.txt");}
	else if(contador==1000)
		{datos(seccion,"fi3o.txt");}
	else if(contador==2000)
		{datos(seccion,"fi4o.txt");}	
	}
	while (++contador <=N);
}

//para bordes abiertos
void ecuaciondifin2(float seccion[][columnas])
{    	int contador = 0;   
    do 	
	for (int x = 1 ; x < filas-2 ; x++)
	{    for (int y = 1 ; y < columnas-2 ; y++)
			{
			circuloV(seccion,r,centrox,centroy);
			seccion[x][y]=(1-(4*dt*v)/(h*h))*seccion[x][y]+(dt*v/h*h)*(seccion[x+1][y]+seccion[x][y+1]+seccion[x-1][y]+seccion[x][y-1]);			
			}
	condicionesFrontera(seccion,N,2);

        if (contador==1)
		{datos(seccion,"ab1o.txt");}		
	else if(contador==500)
		{datos(seccion,"ab2o.txt");}
	else if(contador==1000)
		{datos(seccion,"ab3o.txt");}
	else if(contador==2000)
		{datos(seccion,"ab4o.txt");}	
	}
	while (++contador <=N);
	
}

//bordes periodicos 
void ecuaciondifin3(float seccion[][columnas])
{      int contador = 0;
   do
     for (int x = 1 ; x < filas-2 ; x++)
	{
        for (int y = 1 ; y < columnas-2 ; y++)
	{
          circuloV(seccion,r,centrox,centroy);
	  seccion[x][y]=(1-(4*dt*v)/(h*h))*seccion[x][y]+(dt*v/h*h)*(seccion[x+1][y]+seccion[x][y+1]+seccion[x-1][y]+seccion[x][y-1]);
					
	}
	condicionesFrontera(seccion,25,3);
	if (contador==1)
		{datos(seccion,"pe1o.txt");}		
	else if(contador==500)
		{datos(seccion,"pe2o.txt");}
	else if(contador==1000)
		{datos(seccion,"pe3o.txt");}
	else if(contador==2000)
		{datos(seccion,"pe4o.txt");}	
	}
	while (++contador <=N);
}

//sacamos el promedio
 
double prom(float seccion[][columnas])
{
    double suma = 0.0;
    for (int o = 0; o < filas-2; o++)
    {    for (int p = 0; p < columnas-2; p++)
          {   suma += seccion[o][p]; }
    }
    return suma / (49 * 49);
}





