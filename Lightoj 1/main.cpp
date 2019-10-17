#include <iostream>
#include <stdio.h>
#include <math.h>
//#define pi 3.14159
#include <iomanip>
#define pi acos(-1.0)

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);

    double R,n,result;
    int m=0;
    int testcase;
    cin>>testcase;
    while(testcase--)
    {

        cin>>R>>n;

        result=((R*sin(pi/n))/(1+(sin(pi/n))));
        cout<<fixed<<setprecision(6);
        cout<<"Case "<<++m<<": "<<result<<endl;
       // printf("Case %d: %f\n",++m,result);

    }

    return 0;
}
