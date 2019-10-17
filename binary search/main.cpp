#include <iostream>

using namespace std;

int binary_search(int ar[],int n,int key)
{
    int start=0;
    int endd=n-1;
    int index;

    while(start<=endd)
    {
        int mid=(start+endd)/2;

        if(ar[mid]==key)
        {
            index=mid;
            endd=mid-1;
        }

        else if(ar[mid]< key)
            start=mid+1;
        else
            endd=mid-1;
    }
    return index;
}


int main()
{
    int ar[]= {1,2,3,4,5,6,7};
    int n=sizeof(ar)/sizeof(int);

    int index=binary_search(ar,n,3);
    cout<< index<<endl;

    return 0;
}
