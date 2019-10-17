#include <iostream>

using namespace std;

int main()
{
    int t;
    int a,b,d,m=0;
    cin>>t;

    while(t--)
    {

        cin>>a;
        b=a;
        d=0;
        for(int i=0; a>0; i++)
        {
            d=d*10+a%10;
            a=a/10;
        }

        cout<< "Case "<<++m<<": ";
        if(b==d)
        {
            cout<< "Yes"<<endl;
        }
        else
        {
            cout<< "No"<<endl;
        }

    }

    return 0;
}
