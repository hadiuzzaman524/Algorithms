#include <iostream>
#include <vector>
#include <utility>
#include <stdio.h>

using namespace std;

void print(int ar[])
{
    for(int i=0; i<5; i++)
        cout<< ar[i]<< " ";
    cout<<endl;
}

int main()
{
   int ar[]={1,6,2,3,5};

   print(ar);


    return 0;
}
