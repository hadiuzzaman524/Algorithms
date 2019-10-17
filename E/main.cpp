#include <stdio.h>
#include <stdlib.h>

int main()
{
    char stringC[]="5362";

    for(int test=1 ; test<=100 ; test++)
    {
        char s[5];
        gets(s);
        int bulls=0,cows=0;
        for(int i=0 ; i<4 ; i++)
        {
            if(stringC[i]==s[i])
            {
                bulls++;
                cows=cows;
            }
            if(stringC[i]!=s[i])
            {
                for(int j=0 ; j<4 ; j++)
                {
                    if(stringC[i]==s[j])
                    {
                        cows++;

                    }
                }

            }
        }
        printf("%d %d",bulls,cows);
    }
    return 0;

}
