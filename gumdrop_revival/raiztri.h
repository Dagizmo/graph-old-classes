#include<complex>
//#include<conio.h>
//#include <iostream>
//#include<stdlib.h>
//#include<math.h>
using namespace std;

double raiz(double ox, double oy, double oz, double dx, double dy, double dz){
    complex<double> x[4], R, U, P, Q, y, W;
    //double ox, oy, oz, t, dx, dy, dz;
    double alfa, beta, gamma;
    double min;
    //Datos Estandar de Prueba;
    /*ox=1;
    oy=0;
    oz=0;
    dx=5;
    dy=6;
    dz=7;*/
    //Live Test
    /*ox=-5;
    oy=5;
    oz=1;
    dx=20;
    dy=10;
    dz=75;*/
    /*E=4*pow(ox,4) + 17*pow(ox,2)*pow(oy,2) + 17*pow(ox,2)*pow(oz,2) - 20*pow(ox,2) + 4*pow(oy,4) + 8*pow(oy,2)*pow(oz,2) - 20*pow(oy,2) + 4*pow(oz,4) - 20*pow(oz,2) + 17;
    D=(16*dx*pow(ox,3) + 34*dy*pow(ox,2)*oy + 34*dz*pow(ox,2)*oz + 34*dx*ox*pow(oy,2) + 34*dx*ox*pow(oz,2) - 40*dx*ox + 16*dy*pow(oy,3) + 16*dz*pow(oy,2)*oz + 16*dy*oy*pow(oz,2) - 40*dy*oy + 16*dz*pow(oz,3) - 40*dz*oz);
    C=(24*pow(dx,2)*pow(ox,2) + 17*pow(dx,2)*pow(oy,2) + 17*pow(dx,2)*pow(oz,2) - 20*pow(dx,2) + 68*dx*dy*ox*oy + 68*dx*dz*ox*oz + 17*pow(dy,2)*pow(ox,2) + 24*pow(dy,2)*pow(oy,2) + 8*pow(dy,2)*pow(oz,2) - 20*pow(dy,2) + 32*dy*dz*oy*oz + 17*pow(dz,2)*pow(ox,2) + 8*pow(dz,2)*pow(oy,2) + 24*pow(dz,2)*pow(oz,2) - 20*pow(dz,2));
    B=(16*ox*pow(dx,3) + 34*oy*pow(dx,2)*dy + 34*oz*pow(dx,2)*dz + 34*ox*dx*pow(dy,2) + 34*ox*dx*pow(dz,2) + 16*oy*pow(dy,3) + 16*oz*pow(dy,2)*dz + 16*oy*dy*pow(dz,2) + 16*oz*pow(dz,3));
    A=(4*pow(dx,4) + 17*pow(dx,2)*pow(dy,2) + 17*pow(dx,2)*pow(dz,2) + 4*pow(dy,4) + 8*pow(dy,2)*pow(dz,2) + 4*pow(dz,4));*/

    double E=-20.0*pow(ox,2.0) + 4.0*pow(ox,4.0) - 20.0*pow(oy,2) + 4.0*pow(oy,4) - 20.0*pow(oz,2) + 4.0*pow(oz,4) + 17.0*pow(ox,2)*pow(oy,2) + 17.0*pow(ox,2)*pow(oz,2) + 8.0*pow(oy,2)*pow(oz,2) + 17.0;
    double D=16.0*dx*pow(ox,3.0) + 34.0*dy*pow(ox,2.0)*oy + 34.0*dz*pow(ox,2)*oz + 34.0*dx*ox*pow(oy,2) + 34.0*dx*ox*pow(oz,2) - 40.0*dx*ox + 16.0*dy*pow(oy,3) + 16.0*dz*pow(oy,2)*oz + 16.0*dy*oy*pow(oz,2) - 40.0*dy*oy + 16.0*dz*pow(oz,3) - 40.0*dz*oz;
    double C=24.0*pow(dx,2.0)*pow(ox,2) + 17.0*pow(dx,2)*pow(oy,2) + 17.0*pow(dx,2)*pow(oz,2) - 20.0*pow(dx,2) + 68.0*dx*dy*ox*oy + 68.0*dx*dz*ox*oz + 17.0*pow(dy,2)*pow(ox,2) + 24.0*pow(dy,2)*pow(oy,2) + 8.0*pow(dy,2)*pow(oz,2) - 20.0*pow(dy,2) + 32.0*dy*dz*oy*oz + 17.0*pow(dz,2)*pow(ox,2) + 8.0*pow(dz,2)*pow(oy,2) + 24.0*pow(dz,2)*pow(oz,2) - 20.0*pow(dz,2);
    double B=16.0*ox*pow(dx,3.0) + 34.0*oy*pow(dx,2.0)*dy + 34.0*oz*pow(dx,2)*dz + 34.0*ox*dx*pow(dy,2) + 34.0*ox*dx*pow(dz,2) + 16.0*oy*pow(dy,3) + 16.0*oz*pow(dy,2)*dz + 16.0*oy*dy*pow(dz,2) + 16.0*oz*pow(dz,3);
    double A=4.0*pow(dx,4) + 17.0*pow(dx,2)*pow(dy,2) + 17.0*pow(dx,2)*pow(dz,2) + 4.0*pow(dy,4) + 8.0*pow(dy,2)*pow(dz,2) + 4.0*pow(dz,4);
    //printf("%f\t%f\t%f\t%f\t%f",A,B,C,D,E);
    alfa=((-3.0*pow(B,2.0))/(8.0*pow(A,2.0)))+(C/A);
    beta=(pow(B,3.0)/(8.0*pow(A,3.0)))-((B*C)/(2.0*pow(A,2.0)))+(D/A);
    gamma=((-3.0*pow(B,4.0))/(256.0*pow(A,4.0)))+((C*pow(B,2.0))/(16.0*pow(A,3.0)))-((B*D)/(4.0*pow(A,2.0)))+(E/A);
    //printf("%g \t %g \t %g\n",alfa,beta,gamma);
    if (beta==0){
       x[0]=-(B/(4.0*A))+sqrt((-alfa+sqrt(pow(alfa,2.0)-(4.0*gamma)))/(2.0));
       x[1]=-(B/(4.0*A))+sqrt((-alfa-sqrt(pow(alfa,2.0)-(4.0*gamma)))/(2.0));
       x[2]=-(B/(4.0*A))-sqrt((-alfa+sqrt(pow(alfa,2.0)-(4.0*gamma)))/(2.0));
       x[3]=-(B/(4.0*A))-sqrt((-alfa-sqrt(pow(alfa,2.0)-(4.0*gamma)))/(2.0));
       }
    else {
         P=(-pow(alfa,2.0)/12.0)-gamma;
         Q=(-pow(alfa,3.0)/108.0)+((alfa*gamma)/3.0)-(pow(beta,2.0)/8.0);
         //R=-(Q/2)+sqrt((pow(Q,(2,0))/4)+(pow(P,(3,0))/27));
         R=(-Q/(2.0))+sqrt((pow(Q,2)/(4.0))+(pow(P,3)/(27.0)));
         U=pow(R,(1.0/3.0));
         //cout<< P <<"\n"<< Q << "\n";
         //cout<< R <<"\n"<<U;
         if(U.imag()==0 && U.real()==0)
                  y=(-5.0*alfa/6.0)+U-pow(Q,(1.0/3.0));
         else
                  y=(-5.0*alfa/6.0)+U-(P/(3.0*U));
         W=sqrt(alfa+(2.0*y));
         x[0]=(-B/(4.0*A))+((+W+sqrt(-(3.0*alfa+(2.0*y)+(2.0*beta/W))))/2.0);
         x[1]=(-B/(4.0*A))+((+W-sqrt(-(3.0*alfa+(2.0*y)+(2.0*beta/W))))/2.0);
         x[2]=(-B/(4.0*A))+((-W+sqrt(-(3.0*alfa+(2.0*y)-(2.0*beta/W))))/2.0);
         x[3]=(-B/(4.0*A))+((-W-sqrt(-(3.0*alfa+(2.0*y)-(2.0*beta/W))))/2.0);
         /*for (int i=0; i<4; i++){
             if(x[i].imag()==0)
                                   x[i].imag()=0;
         }   */
         //cout<<"\n---------------------\n"<<x[0]<<"\n"<<x[1]<<"\n"<<x[2]<<"\n"<<x[3];
         }
         /*min=1000;
         for (int i=0; i<4; i++){
             if(x[i].imag()==0 && x[i].real()>0.0)
                               if(min>0.0) {
                                        if(x[i].real()>=0 && x[i].real()<min)
                                                         min=x[i].real();
                                        }
                               else if (min==0)
                               min=x[i].real();

         }*/

         min=1.79769e+308;
        for (int i=0; i<4; i++)
        {
             //if(x[i].imag()==0 && x[i].real()>=0) {
            if((x[i].imag()>-0.11 && x[i].imag() < 0.11)  && x[i].real()>0)
            {
             //if(x[i].imag()<0.000009 && x[i].real()>3) {
             //if(x[i].imag()<5e+1000 && x[i].real()>=0)
             //if(x[i].imag()==0 && x[i].real()>=0){
                if(x[i].real()<=min)
                {
                    min=x[i].real();
                }
            }
        }
         //if(min==3200000)
         //min=0;
         //printf("\n\n%g",min);
    return(min);
}
