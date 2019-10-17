#include <iostream>
#include <string>
#include <sstream>

using namespace std;
long long int factorial(int n)
{
    if(n<1)
        return 1;

    return factorial(n-1)*n;

}

string convert(long int number,long int base)
{
    string temp="";
    long int number1=number;

    for(long int i=0; number1>0; i++)
    {
        temp+=to_string(number1%base);
        number1=number1/base;

    }

    return temp;
}

int main()
{
    /*long int number,base;
    string result="";
    string conversion="";

    // cin>>number>> base;
    long int fac;

    if(base==10)
    {
        fac=factorial(number);
    }
    else
    {
        conversion=convert(number,base);
    }

    //result=to_string(fac);
    // cout<<result;
    cout<< conversion<< endl;
    // cout<< stol(conversion,nullptr,3)<<endl;
    cout<<factorial(40);
    */
    string s="1011";

    int m=stol(s,nullptr,2);

    stringstream  ss;
    ss<< hex<< m;
    string k=ss.str();

    try
    {
        int ff=stol(k,nullptr,10);
         cout<< ff;
    }

    catch(...)
    {
        cout<< "Invalid Input"<<endl;
    }



    return 0;
}
