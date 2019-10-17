#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    //11200 40000 38400
    //freopen("input.txt","r",stdin);

    int testcase;
    cin>>testcase;
    long long int a,b,c;
    long long int ar[3];
    int countt=0;
    while(testcase--)
    {

        cin>>a>>b>>c;
        ar[0]=a;
        ar[1]=b;
        ar[2]=c;

        /*long long int big=ar[0];
        for(int i=1; i<3; i++)
            if(ar[i]>big)
                big=ar[i];

        long long int AB=big;*/
        sort(ar,ar+3);
        long long int AB=ar[2],BC=ar[1],AC=ar[0];

        /* for(int i=0; i<3; i++)
         {
             if(ar[i]!=big)
             {
                 BC=ar[i];
                 AC=ar[i+1];
                 break;
             }
         }*/
         long long int f=AB*AB,g=BC*BC,h=AC*AC;
        /* cout<< AB<< " "<< BC<< " "<< AC<<endl;

         cout<< f<< " "<<g<< " "<< h<< " "<<g+h<<endl;*/

        if(f==g+h)

        {
            cout<< "Case "<<++countt<<": yes"<<endl;
        }
        else
        {
            cout<< "Case "<<++countt<<": no"<<endl;
        }
    }
    return 0;
}
