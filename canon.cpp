#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

float x,y,yo,xo,vo,vox,voy,ang,theta,t,aum,g,cic,yo1,lim,limx;
int cont,cont1;

float guerra(){
    y=yo+voy*aum+0.5*g*pow(aum,2);
    return y;
}

int main () {
    ofstream posicion;
    ofstream velocidad;
    ofstream equis;
    cout << "¿Velocidad del disparo?\n";
    cin >> vo;
    cout << "¿Angulo?\n";
    cin >> ang;
    cout << "¿Tiempo?\n";
    cin >> lim;
    cout << "Pared?";
    cin >> limx;
    theta=ang*M_PI/180.0;
    cont=0;
    t=0;
    xo=0;
    yo=0;
    voy=vo*sin(theta);
    vox=vo*cos(theta);
    g=-1*9.81;
    aum=0.0001;
    cont1=1;

    velocidad.open("h_vs_vel.dat");
    posicion.open("x_vs_y.dat");
    equis.open("equis.dat");

    while (t<=lim)
    {
        cont=cont+1;
        t=t+aum;
        x=xo+vox*aum;  
        if (x>limx){
            vox=-1.0*vox;
            x=2*limx-x;
        }

        if (x<0){
            vox=-1.0*vox;
            x=-1.0*x;
        }
        xo=x;
        y=guerra();
        if (y<=0)
        {
            cont=cont+1;
            voy=(y-yo)/aum;
            voy=-1*voy;
            yo1=y;
            y=-1*y;
            if (cont==cont1*100)
            {    
            cont1=cont1+1;
            posicion << x << "     "<<y<<"\n";
            velocidad << y << "     " << voy <<"\n";
            }
            t=t+aum;
            x=xo+vox*aum;
            if (x<0||x>limx){
            vox=-1.0*vox;
            x=2*limx-x;
            }
            xo=x;
            voy=-1.0*(yo1-yo)/aum;
            yo=y;
            y=guerra();
        if (cont==cont1*100)
        {    
        cont1=cont1+1;
        posicion << x << "     "<<y<<"\n";
        velocidad << y << "     " << voy <<"\n";
        }
            t=t+aum;
            x=xo+vox*aum;   
            if (x<0||x>limx){
            vox=-1.0*vox;
            x=2*limx-x;
            }
            xo=x;
            y=guerra();
        }
        voy=(y-yo)/aum;
        yo=y;
        if (cont==cont1*100)
        {    
        cont1=cont1+1;
        posicion << x << "     "<<y<<"\n";
        velocidad << y << "     " << voy <<"\n";
        }

    }
    cout << "puntos registrados: "<< cont <<"\ncuadros guardados: "<<cont1<<"\n";
    velocidad.close();
    posicion.close();
    equis.close();
    
return(0);
}

