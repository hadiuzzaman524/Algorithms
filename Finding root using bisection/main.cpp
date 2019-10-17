#include <iostream>

using namespace std;
double root(double x)
{
    double low=0;
    double high=x;
    double mid;

    while(high-low>0.00001)
    {
        mid=(low+high)/2;

        if(mid*mid>x)
        {
            high=mid;
        }
        else
            low=mid;
    }
    return mid;

}

int main()
{
    double x=15;
    cout<< root(x)<<endl;
    return 0;
}
