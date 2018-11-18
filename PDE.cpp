#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//inicializamos las constantes 

 const int filas = 500,columnas = 500,r=50,h=1,N=10,centrox=250,centroy=250;
 float k=1.62,cp=820,p=2.71,dt=9.22e-5;
 float v=2710;

void circuloV(float seccion[][columnas],int r, int centrox,int centroy);
void condicionesFrontera(float seccion[][columnas],float temperatura,int caso);
void ecuaciondifin1(float seccion[][columnas]);
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
void condiciones(float seccion [][columnas],float temperatura, int caso)
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
	for (int x = 1 ; x < filas-1 ; x++)
	{
	    for (int y = 1 ; y < columnas-1 ; y++)
			{
                        circuloV(seccion,r,centrox,centroy);
                        condiciones(seccion,10,1);
			seccion[x][y]=(1-(4*dt*v)/(h*h))*seccion[x][y]+(dt*v/h*h)*(seccion[x+1][y]+seccion[x][y+1]+seccion[x-1][y]+seccion[x][y-1]);
			}
	}
	while (++contador <=N);
}

//guarda los datos en un archivo txt 
void datos(float seccion[][columnas], string nombre)
{
  ofstream myfile (string nombre);
  if (myfile.is_open())
  {
    for(int x = 0; x < filas; x ++)
    {
     if(x!=0)	{
     		myfile << "\n";
		}    
     	for(int y = 0; y < columnas; y ++)
     		{  
        	myfile << seccion[x][y] << "," ;
 		}   
    }
    myfile.close();
  }
  else cout << "No se pudieron guardar los datos";
}




}
