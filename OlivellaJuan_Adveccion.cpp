#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>


#define C 1.0


using std::cout;
using std::endl;
using std::array;


int main(){

  int nx = 80;

  float minx = 0.0;

  float maxx = 2.0;

  float dx = (maxx-minx)/(nx);

  float x[nx];

  x[0] = minx;

  for (int i = 1; i < nx; i++){

    x[i] = x[i-1] + dx;

  }

  
  int nt = 30;

  float dt = dx/(2*C);


  float u[nx];

  for (int i = 0; i < nx; i++){

    u[i] = 1.0;

      if(x[i] >= 0.75 && x[i] <= 1.25){

        u[i] = 2.0;
      }
    
    cout << x[i] << "  " << u[i] << endl;

  }


  float r = (dt*C)/(dx);

  float u_pasado[nx];


  for (int j = 0; j < nt; j++){
  
     for (int i = 0; i < nx; i++){

       u_pasado[i] = u[i];
      
     }

    for(int i = 1; i < nx; i++){

      u[i] = (-1)*(r)*(u_pasado[i] - u_pasado[i-1]) + u_pasado[i]; 

      if (j == (nt-1)){

        cout << x[i] << "  " << u[i] << endl;

      }

    }  


  }
  
}