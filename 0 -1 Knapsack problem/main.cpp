#include <iostream>
#define endl "\n"
using namespace std;

int findmax(int value[],int weight[],int n,int s)
{
    int table[n+1][s+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            if(i==0||j==0)
            {
                table[i][j]=0;
            }
            else if(weight[i]>j)
            {
                table[i][j]=table[i-1][j];
            }
            else
            {
                int lave=table[i-1][j];
                int take=table[i-1][j-weight[i]]+value[i];

                table[i][j]=max(lave,take);
            }
        }
    }
    return table[n][s];
}


int main()
{
    // freopen("input.txt","r",stdin);

    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int n;
        // cout<< "how many element : ";
        cin>>n;

        int value[n+1];
        int weight[n+1];
        value[0]=0;
        weight[0]=0;


        for(int i=1; i<=n; i++)
        {
            cin>>value[i]>>weight[i];
        }

        int z=0;
        int person;
        //  cout<< "enter person: ";
        cin>>person;

        for(int i=0; i<person; i++)
        {
            int s;
            // cout<< "enter the size of knapsack: ";
            cin>>s;
            z+=findmax(value,weight,n,s);
        }


        cout<<z<<endl;
    }

    return 0;
}
