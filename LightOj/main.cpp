#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int testcase;
    cin>>testcase;

    int Y,Z;
    int n,m;
    int jaman=0;

    while(testcase--)
    {
        cin>>n>>m;
        int ar[n];
        for(int i=0; i<n; i++)
        {
            cin>>ar[i];
        }

        for(int i=0; i<m; i++)
        {
            int data=0;
            char ch;
            cin>>ch;
            switch(ch)
            {
            case 'S':
            {
                cin>>data;
                for(int j=0; j<n; j++)
                {
                    ar[j]+=data;
                }
                break;
            }
            case 'M':
            {
                cin>>data;
                for(int j=0; j<n; j++)
                {
                    ar[j]*=data;
                }
                break;
            }
            case 'R':
            {
                reverse(ar,ar+n);
                break;
            }
            case 'D':
            {
                cin>>data;
                for(int j=0; j<n; j++)
                {
                    ar[j]/=data;
                }
                break;
            }
            case 'P':
            {
                cin>>Y>>Z;
                int temp=ar[Z];
                ar[Z]=ar[Y];
                ar[Y]=temp;
                break;
            }
            default:
            {

            }


            }
        }

        cout<< "Case "<< ++jaman<< ": "<<endl;

        bool flag=false;
        for(int i=0; i<n; i++)
        {


            if(flag==true)
            {
                cout<<" ";

            }
            cout<<ar[i];
            flag=true;
        }
        cout<<endl;

    }
    return 0;
}
