#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);

    int test,ii,cnt1,cnt2,res,c;

    char ara[100];
    long long int n,result,i,j,h;
    scanf("%d",&test);

    //convert binary and count 1
    for(ii=1; ii<=test; ii++)
    {
        scanf("%lld",&n);
        result=0;
        cnt1=0;
        cnt2=0;
        for(i=0; n>0; i++)
        {
            if(n%2==1)
            {
                ara[i]='1';
                cnt1+=1;
            }
            else
                ara[i]='0';
            n=n/2;
        }

        ara[i]='\0';

        j=0;
        for(j=0;; j++)
        {
            if(ara[j]=='1')
            {

                while(ara[j]=='1')
                {
                    ara[j]='0';
                    j++;
                }
                ara[j]='1';

                break;
            }
        }

        if(i==j)
            ara[j+1]='\0';
        else
            ara[i]='\0';

        for(i=0; ara[i]!='\0'; i++)
        {
            if(ara[i]=='1')
                cnt2++;

            else
                continue;
        }

        c=cnt1-cnt2;

        for(h=0; h<c; h++)
        {
            ara[h]='1';
        }


        for(h=0; ara[h]!='\0'; h++)
        {
            res = ara[h] - 48;
            result = result + res * pow (2, h);
        }

        printf ("Case %d: %lld\n", ii, result);

    }

    return 0;
}
