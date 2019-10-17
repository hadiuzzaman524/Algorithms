#include <iostream>

using namespace std;

int modular_inv(int a,int m)
{
    a=a%m;

    for(int i=1; i<m; i++)
    {
        if(((a*i)%m)==1)
            return i;
    }
}
int main()
{
   cout<< modular_inv(3,11);
    return 0;
}
