#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

//inicializamos las constantes 

 const int filas = 50,columnas = 50,r=5,N=5,centrox=25,centroy=25;
const  float k=1.62e4,cp=820e10,p=2.71,h=1.0;
const float v=2710,dt=(h*h)/(4*v);

void circuloV(float seccion[][columnas],int r, int centrox,int centroy);
void condicionesFrontera(float seccion[][columnas],float temperatura,int caso);
void ecuaciondifin1(float seccion[][columnas]);
void ecuaciondifin2(float seccion[][columnas]);
void datos(float seccion[][columnas], string nombre);

int main()
{
 float roca[filas][columnas] = {};
 ecuaciondifin1(roca);
 datos(roca,"circulo.txt");
 return 0;
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
		for (int y = 0 ; y < columnas-1 ; y++)             //condiciones de frontera fijas
			{	seccion[0][y]=temperatura;
				seccion[filas-1][y]=temperatura;
				seccion[y][0]=temperatura;
				seccion[y][columnas-1]=temperatura;
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
			{	seccion[0][y]=10;
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
	for (int x = 1 ; x < filas ; x++)
	{
		
		
		for (int y = 1 ; y < columnas ; y++)
			{
			circuloV(seccion,r,centrox,centroy);
			seccion[x][y]=(1-(4*dt*v)/(h*h))*seccion[x][y]+(dt*v/h*h)*(seccion[x+1][y]+seccion[x][y+1]+seccion[x-1][y]+seccion[x][y-1]);
			condicionesFrontera(seccion,10,1);
			}
	}

	while (++contador <=N);
}




//guarda los datos en un archivo txt 
void datos(float seccion[][columnas], string nombre)

{  ofstream myfile (nombre);
  if (myfile.is_open())
  {
    for(int x = 0; x < filas-1; x ++)
    {
	if(x!=0)
			{
     			myfile << "\n";
			}    
     	
     	for(int y = 0; y < columnas-1; y ++)
     		{  
        	myfile << seccion[x][y] << "," ;
 			}   
    }	
    myfile.close();
  }
  else cout << "no se pudo abrir el archivo";
}





