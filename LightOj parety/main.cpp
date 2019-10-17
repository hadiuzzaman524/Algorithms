#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    int test,n,x;

    cin>>test;
    int m=0;

    while(test--)
    {
        string s="";
        cin>>n;
        for(int i=0; n>0; i++)
        {
            s+=to_string(n%2);
            n=n/2;
        }
        x=count(s.begin(),s.end(),'1');

        if(x%2!=0)
        {
            cout<< "Case "<<++m<<": odd"<<endl;
        }
        else
        {
            cout<<  "Case "<<++m<<": even"<<endl;
        }

    }

    return 0;
}
