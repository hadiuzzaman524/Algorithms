#include <iostream>
using namespace std;

int ndigit(int n,int lastdigit)
{
    if(n==0)
        return 0;

    if(n==1)
    {
        if(lastdigit)
            return 1;
        else
            return 2;
    }

    if(lastdigit==0)
        return ndigit(n-1,0)+ndigit(n-1,1);
    else
        return ndigit(n-1,0);

}

int main()
{
  int n=3;
  cout<< "Result is: "<< ndigit(n,0);
    return 0;
}
