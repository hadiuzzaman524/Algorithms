
#include <iostream>
#include <vector>
using namespace std;

int findlen(int ar[],int n)
{
    int la[n]= {0};
    la[0]=2;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(ar[j]<ar[i]&&la[j]>la[i])
            {
                la[i]=la[j];
            }
        }
        la[i]++;
    }
    int result=0;
    for(int x:la)
    {
        result=max(result,x);
    }
    return result;

}

int main()
{
    freopen("input.txt","r",stdin);
    /* int ar[]= {0, 1,2,3,2,1,2, 1, 2,3,4};
     // int ar[]={5,4,3,2,1};
     int n=sizeof(ar)/sizeof(int);

     int xx=findlen(ar,n);

     if(xx<=2)
         cout<< "0"<<endl;
     else
         cout<< xx<<endl;*/


    int n;
    cin>>n;
    while(n--)
    {
        int arsize;
        cin>>arsize;
        int ar[arsize+1];
        for(int i=0; i<arsize; i++)
        {
            cin>>ar[i];
        }
        int xx=findlen(ar,arsize);

        if(xx<=2)
            cout<< "0"<<endl;
        else
            cout<< xx<<endl;

    }

    return 0;
}
