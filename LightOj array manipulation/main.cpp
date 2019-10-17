#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);

    int testcase;
    int n,m,Data,K,Y,Z,jaman;

    char ch;
    cin>>testcase;
    int x=0;


    while(testcase--)
    {


        cin>>n>>m;

        int ar[n];

        for(int i=0; i<n; i++)
        {
            cin>>ar[i];
        }

        while(m--)
        {
            scanf("%c",&ch);

            if(ch=='S')
            {
                cin>>Data;
                for(int j=0; j<n; j++)
                {
                    ar[j]=ar[j]+Data;
                }
                continue;
            }

            else if(ch=='P')
            {
                cin>>Y>>Z;
                int temp=ar[Z];
                ar[Z]=ar[Y];
                ar[Y]=temp;
                continue;
            }
            else if(ch=='R')
            {
                reverse(ar,ar+n);
                continue;
            }

            else if(ch=='D')
            {
                cin>>K;
                if(K>0)
                {
                    for(int j=0; j<n; j++)
                        ar[j]=ar[j]/K;
                }
                continue;
            }

            else if(ch=='M')
            {
                cin>>jaman;
                for(int j=0; j<n; j++)
                    ar[j]=ar[j]*jaman;
                    continue;
            }

        }


        cout<< "Case "<<++x<<":"<<endl;

        for(int i=0; i<n; i++)

        cout<< ar[i]<< " ";

        cout<<endl;
    }

    return 0;
}
