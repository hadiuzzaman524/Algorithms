#include<iostream>
using namespace std;
int main()
{
    int number;
    cin>>number;

    if(number%3==0)
        cout<<"1 1 "<<number-2;
    else
        cout<<"1 2 "<<number-3;

    return 0;
}
