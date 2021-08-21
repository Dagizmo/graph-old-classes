#include <winbgim.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "raiztri.h"
#include "vectorlib/libreriavector.h"

using namespace std;


int main()
{
    double fovx, fovy, dis, hsize, vsize, hpixel, vpixel, TEMP, TEMP2, t;
    CVector3 VTEMP, VTEMP2, VTEMP3, PIXEL, P, g, V, L, N, ref;
    double do1, do2;
    double horizontal, vertical;
    double ns;
    //IMAGEN[50][50][2]=4;
    horizontal=500;
    vertical=500;
    //DECLARACIONES NUEVAS
    //MATERIAL
    CVector3 Ia = CVector3(0.2, 0.2, 0.2);
    CVector3 Ka = CVector3(0.1, 0.1, 0.1);
    CVector3 Kd = CVector3(0.0, 0.0, 1.0);
    CVector3 Ks = CVector3(0.9, 0.8, 0.6);
    ns=30;
    CVector3 P1 = CVector3(7.2, -10.0, 0.0);
    CVector3 I1 = CVector3(1.0, 1.0, 1.0);
    fovx=M_PI/4;
    fovy=M_PI/4;
    dis=1.0;

    CVector3 EYE = CVector3(1.0, 1.0, 5.0);
    CVector3 LOOKAT = CVector3(0.0, 0.0, 0.0);
    CVector3 UP = CVector3(0.0, 0.0, 1.0);

    CVector3 VIEW=LOOKAT-EYE;
    VIEW=Normalized(VIEW);
    CVector3 CENTER=VIEW*dis;
    CENTER=CENTER+EYE;

    CVector3 HORZ=Normalized(CrossProduct(UP,VIEW));

    CVector3 VERT=CrossProduct(VIEW,HORZ);
    VERT=Normalized(VERT);
    hsize=2*dis*tan(fovx/2.0);
    vsize=2*dis*tan(fovy/2.0);
    hpixel=hsize/horizontal;
    vpixel=vsize/vertical;

    CVector3 ORIGIN=CENTER-(HORZ * (((horizontal-1)/2.0)*hpixel))+(VERT * (((vertical-1)/2.0)*vpixel));
    initwindow(horizontal,vertical);
    for(int i=0; i<horizontal; i++)
    {
        for(int j=0; j<vertical; j++)
        {
            PIXEL=ORIGIN+((HORZ * (i*hpixel))-(VERT * (j*vpixel)));
            //FIN CALCULO PIXEL
            //INTERSECCION
            t=raiz(1.0,1.0,5.0,Normalized(PIXEL-EYE).X,Normalized(PIXEL-EYE).Y,Normalized(PIXEL-EYE).Z);

            P=EYE+(Normalized(PIXEL - EYE) * t);
            /*g.x=-4*pow(P.x,3)+12*pow(P.x,5)-8*pow(P.x,7)+4*P.x*pow(P.y,2)-8*pow(P.x,3)*pow(P.y,2);
            g.y=4*pow(P.x,2)*P.y-4*pow(P.x,4)*P.y-4*pow(P.y,3);
            g.z=-2*P.z;*/
            CVector3 g = CVector3((4*4*pow(P.X,3)+17*2*P.X*(pow(P.Y,2)+pow(P.Z,2))-40*P.X),
                                  (4*2*(pow(P.Y,2)+pow(P.Z,2))*2*P.Y+17*pow(P.X,2)*2*P.Y-40*P.Y),
                                  (4*2*(pow(P.Y,2)+pow(P.Z,2))*2*P.Z+17*pow(P.X,2)*2*P.Z-40*P.Z));

            //BOMBER
            //AHORA COON V!!!!
            N=Normalized(g);
            V=EYE-P;
            if (V.X!=0 && V.Y!=0 && V.Z !=0)
               V=Normalized(V);
            L=Normalized(P1-P);
            do1=DotProduct(L,N);
            if (do1<0)
               do1=0;
            ref=((N-L)*(2*do1));
            do2=DotProduct(V,ref);
            if (do2<0)
               do2=0;
            CVector3 Ilocal = CVector3((Ka.X*Ia.X + I1.X*((Kd.X*do1)+(Ks.X*pow(do2,ns)))),
                                       (Ka.Y*Ia.Y + I1.Y*((Kd.Y*do1)+(Ks.Y*pow(do2,ns)))),
                                       (Ka.Z*Ia.Z + I1.Z*((Kd.Z*do1)+(Ks.Z*pow(do2,ns)))));
            //w=399-i;

            int r = (Ilocal.X*255) > 255 ? 255 : (Ilocal.X*255);
            int green = (Ilocal.Y*255) > 255 ? 255 : (Ilocal.Y*255);
            int b =  (Ilocal.Z*255) > 255 ? 255 : (Ilocal.Z*255);

            putpixel(i,j,COLOR(r,green,b));
        }
    }

    getch();
	return 0;
}


