#include <iostream>
#include <vector>

using namespace std;

int mlis(int ar[],int n)
{
    int sum[n]= {0};
    vector<int>v[n];

    v[0].push_back(ar[0]);
    sum[0]=ar[0];

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(ar[i]>ar[j]&&sum[j]>sum[i])
            {
                v[i]=v[j];
                sum[i]=sum[j];
            }

        }
        v[i].push_back(ar[i]);
        sum[i]+=ar[i];
    }

    int m=0;
    int index;

    for(int i=1; i<n; i++)
    {
        if(sum[i]>m)
        {
            m=sum[i];
            index=i;
        }

    }


    cout<< "Selected Element are: "<<endl;
    for(int i=0; i<v[index].size(); i++)
    {
        cout<< v[index][i]<< " ";
    }
    cout<<endl;
    return m;

}



int main()
{
    int ar[]= {0,8,4,12,2,10,6, 14,1,9,5,13,3,11};

    int n=sizeof(ar)/sizeof(int);

    int z=mlis(ar,n);

    cout<< "maximum sum is: "<<z<<endl;



    return 0;
}
