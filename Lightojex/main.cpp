#include <bits/stdc++.h>

using namespace std;

int maximum(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    long k;
    //cin>>n>>k;
    scanf("%d%ld",&n,&k);

    int ar[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }

    int big;
if(k!=0)
{
    if(k%2==0)
        k=2;
    else
        k=1;
}
    while(k--)
    {
        big=0;

        for(int x:ar)
        {
            big=maximum(big,x);
        }

        for(int i=0; i<n; i++)
        {
            ar[i]=big-ar[i];
        }

    }


    for(int i=0; i<n; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");

    return 0;
}
