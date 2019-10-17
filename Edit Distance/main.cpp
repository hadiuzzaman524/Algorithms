#include <iostream>
#include <string>
using namespace std;

int edit_distance(string x,string y,int n,int m)
{
    if(n==0)
        return m;
    if(m==0)
        return n;
     int cost;

     if(x[n-1]==y[m-1])
     {
         cost=0;
     }
     else
        cost=1;

     return min(min(edit_distance(x,y,n-1,m)+1,edit_distance(x,y,n,m-1)+1),edit_distance(x,y,n-1,m-1)+cost);

}

int main()
{
   string x="kitten";
   string y="sitting";

   int n=x.length();
   int m=y.length();

   int z=edit_distance(x,y,n,m);

   cout<< "Total operation is: "<< z<<endl;

    return 0;
}
