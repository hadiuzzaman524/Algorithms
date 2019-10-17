#include <iostream>

using namespace std;


bool part(int s[],int n,int sum)
{

    bool table[n+1][sum+1];

    for(int i=0; i<=n; i++)
    {
        table[i][0]=true;
    }

    for(int i=1; i<=sum; i++)
    {
        table[0][i]=false;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(s[i-1]>j)
                table[i][j]=table[i-1][j];
            else
            {

                table[i][j]  = table[i-1][j] || table[i-1][j-s[i-1]];

            }
        }
    }

    return table[n][sum];

}


bool partition_s(int s[],int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=s[i];
    }
    if(sum%2==0)
    {
        return part(s,n,sum/2);
    }
    else
    {
        return false;
    }
}


int main()
{
    int s[]= {3,1,1,2,2,1};

    int n=sizeof(s)/sizeof(int);

    bool p=partition_s(s,n);

    if(p)
    {
        cout<< "Yes"<<endl;
    }
    else
    {
        cout<< "No"<<endl;
    }

    return 0;
}
