#include <iostream>

using namespace std;

int main()
{ freopen("input.txt","r",stdin);

    int caseno=0;
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int x1,x2,y1,y2;
        bool flag=true;
        cin>>x1>>y1>>x2>>y2;
        int n;
        cin>>n;

        while(n--)
        {
            int x,y;
            cin>>x>>y;
            if(flag==true)
            {
                cout<< "Case "<<++caseno<<":"<<endl;
                flag=false;
            }

            if(y>y1&&y<y2&&x<x2&&x>x1)
            {
                cout<<"Yes"<<endl;
            }
            else
                cout<< "No"<<endl;
        }

    }


    return 0;
}
