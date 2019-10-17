#include <iostream>
#include <math.h>
#define pi acos(-1)
using namespace std;

int main()
{ cout<<pi<<endl;
   int R,r,h,p;
   double theta;
   cin>>R>>r>>h>>p;
   theta=atan((h/(R-r))*pi/180);
   double x;
   x=p/tan(theta*(pi/180));

   double R2=r+x;

   double volume=(((pi*p)/3)*(R2*R2+R2*r+r*r));
   cout<<volume<<endl;

    return 0;
}
