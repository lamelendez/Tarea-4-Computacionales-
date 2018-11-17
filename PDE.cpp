#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int filas = 500 , columnas = 500, varilla=100;
float k=1.62,cp=820,p=2.71;
float v=k/(cp*p);

int main()

 return 0;
}


void ecuaciondifin(float seccion[][columnas])
{
	int contador = 0;
        do {	
	for (int x = 1 ; x < filas-1 ; x++)
	{
		for (int y = 1 ; y < columnas-1 ; y++)
			{
			seccion[x][y]=v*(seccion[x+1][y]+seccion[x][y+1]+seccion[x-1][y]+seccion[x][y-1]);
			}
	}
        }
	while (++contador<=N);
}
