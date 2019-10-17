#include<stdio.h>
#include <iostream>

using namespace std;
int main()
{

    int num1,num2,num3,num4;
    scanf("%d",&num1);


    num2 = num1/3;
    if(num2 %3==0)
    {
        num2+=1;
    }
    num3 = num2;
    num4 = num1 - (num2 + num3);

    printf("%d %d %d\n",num2,num3,num4);


    return 0;
}

