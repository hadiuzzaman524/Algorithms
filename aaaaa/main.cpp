#include <iostream>
#include <math.h>
#include <iomanip>
#define pi acos(-1)
#include <stdio.h>
using namespace std;

int main()
{ int t;
  cin>>t;
    int R,r,h,p,x=0;
    while(t--)
    {
    cin>>R>>r>>h>>p;

    double volume;
    double R1=(R-r)*(double)p/h + r;
    volume=(pi*p/3)*(R1*R1+R1*r+r*r);
   // printf("Case %d: %lf\n",++x,volume);
   cout<< fixed<< setprecision(8);
   cout<< "Case "<<++x<<": "<< volume<<endl;

    }
    return 0;
}
