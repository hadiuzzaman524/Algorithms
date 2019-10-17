#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);

    int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy,x,y;
    int t,m=0;
    cin>>t;
    while(t--)
    {
        cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;
        // x=(Ax+Cx)/2;
        //y=(Ay+Cy)/2;

        Dx=Ax+Cx-Bx;
        Dy=Ay+Cy-By;

        /* Ax Ay
           Bx By
           Cx Cy
           Dx Dy
           Ax Ay

        */
        int area=0.5*(((Ax*By)+(Bx*Cy)+(Cx*Dy)+(Dx*Ay))-((Ay*Bx)+(By*Cx)+(Cy*Dx)+(Dy*Ax)));
        if(area<0)
            area=area*-1;
            //cout<< fixed<< setprecision(0);
        cout<<"Case "<<++m<<": "<< Dx<< " "<< Dy<< " "<< area<< endl;

    }


    return 0;
}
