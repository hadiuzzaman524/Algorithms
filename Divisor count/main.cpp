#include <stdio.h>
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return (gcd(b%a,a));
}

int main()
{
    int test;
    int a,b;
    scanf("%d",&test);


    while(test--)
    {
        scanf("%d%d",&a,&b);

        int g=gcd(a,b);
        int countt=0;

        for(int i=1; i*i<=g; i++)
        {
            if(i*i==g)
            {
                countt++;
            }
            else if(g%i==0)
            {
                countt+=2;
            }

        }
      printf("%d\n",countt);
    }
    return 0;
}
