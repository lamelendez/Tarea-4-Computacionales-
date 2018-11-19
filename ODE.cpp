#include <iostream>
#include <iomanip>
#include <cmath>
#include <functional>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const float PI 3.14159265
const float g=10,c=0.2,m=2,dt=0.5;
const int filas = 300,columnas = 4;


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

int main()
{

}
float xo = 0.0;
float yo = 0.0;
float v1 = 300.;
float ang = 45.;
float vox = v1*cos(ang*(PI/180));
float vox = v1*sen(ang*(PI/180));   // velocidades iniciales en x y ya dadas por el enunciado


//nuestra fun es la aceleracion

float funx(float c, float m,float vx, float vy, float g){
 float aceleracion = -(c*vx*norma(vx,vy))/m;
 return acerelacion;
}

float funy(float c, float m,float vx, float vy, float g){
 float aceleracion = -g-((c*vx*norma(vx,vy))/m);
 return aceleracion;
}



float	k1x=funx(xo,yo); //fun es la de la aceleracion
float	k2x=funx(xo+0.5*dt,(yo+0.5*k1_c*dt));
float	k3x=funx(xo+0.5*dt,(yo+0.5*k2_c*dt));
float	k4x=funx(xo+dt,(yo+k3_c*dt));
float	k1y=funy(xo,yo);
float	k2y=funy(xo+0.5*dt,(yo+0.5*k1_c*dt));
float	k3y=funy(xo+0.5*dt,(yo+0.5*k2_c*dt));
float	k4y=funy(xo+dt,(yo+k3_c*dt));





